/*
Hardware frontend for Voctomix
https://github.com/voc/voctomix
created 9. Nov 2017
last changed 25. December 2017

With help from
http://www.arduino.cc/en/Tutorial/ButtonStateChange
and many friends
*/

#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "Timer.h"
#include "TimerOne.h"

#define LED_TEST_FLASH_DURATION 50      // ms
#define UPDATE_STREAM_STATE     1000    // ms

static Adafruit_MCP23017 mcp1; // MCP 1 (U1)
static Adafruit_MCP23017 mcp2; // MCP 2 (U2)

static Timer stream_state_timer;

// pin mapping

enum io_pin_modes_e {
    IO_INPUT = INPUT,
    IO_OUTPUT = OUTPUT
};

enum io_pin_state_e {
    IO_HIGH = HIGH,
    IO_LOW = LOW,
    IO_IGNORE = -1
};

struct mcp_io_cfg_s {
    Adafruit_MCP23017 *mcp_number;      // associated i/o multiplexer
    int pin;                            // pin number
    enum io_pin_modes_e mode;           // mode (input/output)
    enum io_pin_state_e init_state;     // set the pin high or low upon initialization (output)
                                        // or assume that it is in this state (input)
};

struct buttons_s {
    const struct mcp_io_cfg_s *mcp_io_cfg;    // matching entry from struct mcp_io_cfg_s
    const char *cmd_string;                   // the matching command
    const struct mcp_io_cfg_s *mating_led;    // the led which belongs to the button
};

struct button_classes_s {
    const struct buttons_s *button_group;   // matching buttons array
    const unsigned int member_count;        // count of members
    struct buttons_s *selected_button;      // currently selected button
};

const struct mcp_io_cfg_s mcp_io_cfg[] PROGMEM = {
    //  mcp_number  pin     mode        init_state
    {   &mcp1,      0,      IO_INPUT,   IO_HIGH     },  // 0:  button_cam1_a
    {   &mcp1,      1,      IO_OUTPUT,  IO_LOW      },  // 1:  led_cam1_a
    {   &mcp1,      2,      IO_INPUT,   IO_HIGH     },  // 2:  button_cam2_a
    {   &mcp1,      3,      IO_OUTPUT,  IO_LOW      },  // 3:  led_cam2_a
    {   &mcp1,      4,      IO_INPUT,   IO_HIGH     },  // 4:  button_cam3_a
    {   &mcp1,      5,      IO_OUTPUT,  IO_LOW      },  // 5:  led_cam3_a
    {   &mcp1,      8,      IO_INPUT,   IO_HIGH     },  // 6:  button_fullscreen
    {   &mcp1,      9,      IO_OUTPUT,  IO_LOW      },  // 7:  led_fullscreen
    {   &mcp1,      10,     IO_INPUT,   IO_HIGH     },  // 8:  button_side_by_side_preview
    {   &mcp1,      11,     IO_OUTPUT,  IO_LOW      },  // 9:  led_side_by_side_preview
    {   &mcp1,      12,     IO_INPUT,   IO_HIGH     },  // 10: button_picture_in_picture
    {   &mcp1,      13,     IO_OUTPUT,  IO_LOW      },  // 11: led_picture_in_picture
    {   &mcp1,      14,     IO_INPUT,   IO_HIGH     },  // 12: button_slides_a
    {   &mcp1,      15,     IO_OUTPUT,  IO_LOW      },  // 13: led_slides_a

    {   &mcp2,      0,      IO_INPUT,   IO_HIGH     },  // 14: button_take
    {   &mcp2,      1,      IO_OUTPUT,  IO_LOW      },  // 15: led_take
    {   &mcp2,      5,      IO_INPUT,   IO_HIGH     },  // 16: button_stream
    {   &mcp2,      6,      IO_OUTPUT,  IO_LOW      },  // 17: led_stream_red
    {   &mcp2,      7,      IO_OUTPUT,  IO_LOW      },  // 18: led_stream_green
    {   &mcp2,      8,      IO_INPUT,   IO_HIGH     },  // 19: button_slides_b
    {   &mcp2,      9,      IO_OUTPUT,  IO_LOW      },  // 20: led_slides_b
    {   &mcp2,      10,     IO_INPUT,   IO_HIGH     },  // 21: button_cam1_b
    {   &mcp2,      11,     IO_OUTPUT,  IO_LOW      },  // 22: led_cam1_b
    {   &mcp2,      12,     IO_INPUT,   IO_HIGH     },  // 23: button_cam2_b
    {   &mcp2,      13,     IO_OUTPUT,  IO_LOW      },  // 24: led_cam2_b
    {   &mcp2,      14,     IO_INPUT,   IO_HIGH     },  // 25: button_cam3_b
    {   &mcp2,      15,     IO_OUTPUT,  IO_LOW      }   // 26: led_cam3_b
};

const struct buttons_s btn_take[] PROGMEM = {
    //  mcp_io_cfg          cmd_string              mating_led
    {   &mcp_io_cfg[14],    NULL,                   &mcp_io_cfg[15]  }      // 0
};

const struct buttons_s btn_stream[] PROGMEM = {
    //  mcp_io_cfg          cmd_string              mating_led
    {   &mcp_io_cfg[16],    NULL,                   NULL             }      // 0
};

const struct buttons_s btn_source_a[] PROGMEM = {
    //  mcp_io_cfg          cmd_string              mating_led
    {   &mcp_io_cfg[12],    "slides",               &mcp_io_cfg[13]  },     // 0
    {   &mcp_io_cfg[0],     "cam1",                 &mcp_io_cfg[1]   },     // 1
    {   &mcp_io_cfg[2],     "cam2",                 &mcp_io_cfg[3]   },     // 2
    {   &mcp_io_cfg[4],     "cam3",                 &mcp_io_cfg[5]   }      // 3
};

const struct buttons_s btn_source_b[] PROGMEM = {
    //  mcp_io_cfg          cmd_string              mating_led
    {   &mcp_io_cfg[19],    "slides",               &mcp_io_cfg[20]  },     // 0
    {   &mcp_io_cfg[21],    "cam1",                 &mcp_io_cfg[22]  },     // 1
    {   &mcp_io_cfg[23],    "cam2",                 &mcp_io_cfg[24]  },     // 2
    {   &mcp_io_cfg[25],    "cam3",                 &mcp_io_cfg[26]  }      // 3
};

const struct buttons_s btn_composition[] PROGMEM = {
    //  mcp_io_cfg          cmd_string              mating_led
    {   &mcp_io_cfg[6],     "fullscreen",           &mcp_io_cfg[7]   },     // 0
    {   &mcp_io_cfg[8],     "side_by_side_preview", &mcp_io_cfg[9]   },     // 1
    {   &mcp_io_cfg[10],    "picture_in_picture",   &mcp_io_cfg[11]  }      // 2
};

volatile struct button_classes_s btn_classes[] = {
    //  button_group        member_count                                selected_button
    {   btn_composition,    sizeof(btn_composition)/sizeof(buttons_s),  NULL    },  // 0
    {   btn_source_a,       sizeof(btn_source_a)/sizeof(buttons_s),     NULL    },  // 1
    {   btn_source_b,       sizeof(btn_source_b)/sizeof(buttons_s),     NULL    },  // 2
    {   btn_take,           sizeof(btn_take)/sizeof(buttons_s),         NULL    },  // 3
    {   btn_stream,         sizeof(btn_stream)/sizeof(buttons_s),       NULL    }   // 4
};

char *src_a = "slides";
char *src_b = "cam1";
char *composition_mode = "side_by_side_preview";

String curr_stream_status;
String last_stream_status;

boolean init_mcp_io() {
    // loop trough each entry of "mcp_io_cfg"
    for (unsigned int i = 0; i < sizeof(mcp_io_cfg)/sizeof(mcp_io_cfg_s); i++) {
        // copy single config (temporarily) from flash into sram
        mcp_io_cfg_s cfg;
        memcpy_P(&cfg, &mcp_io_cfg[i], sizeof(mcp_io_cfg_s));

        cfg.mcp_number->pinMode(cfg.pin, cfg.mode);

        if (IO_OUTPUT == cfg.mode) {
            cfg.mcp_number->digitalWrite(cfg.pin, cfg.init_state);
        }
    }

    return true;
}

boolean mcp_flash_led(mcp_io_cfg_s cfg, int duration) {
    cfg.mcp_number->digitalWrite(cfg.pin, HIGH);
    delay(duration);
    cfg.mcp_number->digitalWrite(cfg.pin, LOW);

    delay(duration/10);

    return true;
}

boolean test_leds() {
    for (unsigned int i = 0; i < sizeof(btn_classes)/sizeof(struct button_classes_s); i++) {
        for (unsigned int j = 0; j < btn_classes[i].member_count; j++) {
            buttons_s button;
            memcpy_P(&button, &btn_classes[i].button_group[j], sizeof(buttons_s));
            mcp_io_cfg_s cfg;
            memcpy_P(&cfg, button.mating_led, sizeof(mcp_io_cfg_s));

            mcp_flash_led(cfg, LED_TEST_FLASH_DURATION);
        }
    }

    digitalWrite(mcp_io_cfg[17].pin, HIGH);
    digitalWrite(mcp_io_cfg[18].pin, HIGH);

    delay(1000);

    digitalWrite(mcp_io_cfg[17].pin, LOW);
    digitalWrite(mcp_io_cfg[18].pin, LOW);

    return true;
}

void setup() {

    mcp1.begin(0);      // Start MCP 1 on Hardware address 0x20
    mcp2.begin(1);      // Start MCP 2 on Hardware address 0x21

    if (!init_mcp_io()) {
        // TODO Error Handling
    }

    // initialize the button pins as input:
    pinMode(mcp_io_cfg[16].pin, INPUT);

    // initialize the LEDs as output:
    pinMode(mcp_io_cfg[17].pin, OUTPUT);
    pinMode(mcp_io_cfg[18].pin, OUTPUT);

    if (!test_leds()) {
        // TODO Error Handling
    }

    // update_button_states();
    Timer1.initialize(50000);
    Timer1.attachInterrupt(update_button_states);

    // initialize serial communication:
    Serial.begin(9600);

    stream_state_timer.every(UPDATE_STREAM_STATE, request_stream_state);
}

void update_button_states(void) {
    // time consumption: up to 4mS

    boolean change_flag = false;

    sei();
    uint16_t mcp1_gpios = mcp1.readGPIOAB();
    uint16_t mcp2_gpios = mcp2.readGPIOAB();
    cli();

    //
    // read button states from port expanders
    //
    for (unsigned int i = 0; i < sizeof(btn_classes)/sizeof(struct button_classes_s); i++) {
        for (unsigned int j = 0; j < btn_classes[i].member_count; j++) {
            // copy single config (temporarily) from flash into sram
            buttons_s button;
            memcpy_P(&button, &btn_classes[i].button_group[j], sizeof(buttons_s));
            mcp_io_cfg_s cfg;
            memcpy_P(&cfg, button.mcp_io_cfg, sizeof(mcp_io_cfg_s));

            uint16_t *mcp_gpios;
            if (&mcp1 == cfg.mcp_number) {
                mcp_gpios = &mcp1_gpios;
            } else if (&mcp2 == cfg.mcp_number) {
                mcp_gpios = &mcp2_gpios;
            }

            if (0 != (*mcp_gpios & (1 << cfg.pin))) {
                if (
                    btn_classes[i].selected_button !=
                    (buttons_s *)&btn_classes[i].button_group[j]
                ) {
                    change_flag = true;
                }
                btn_classes[i].selected_button =
                    (buttons_s *)&btn_classes[i].button_group[j];
                break;
            }
        }
    }

    //
    // update LEDs
    //

    mcp1_gpios = 0;
    mcp2_gpios = 0;

    // have we received a complete stream_status?
    if (curr_stream_status.endsWith("\n")) {
        if (curr_stream_status.startsWith("stream_status live")) {
            mcp2_gpios = mcp2_gpios | (1 << mcp_io_cfg[18].pin);
        } else if (curr_stream_status.startsWith("stream_status")) {
            mcp2_gpios = mcp2_gpios | (1 << mcp_io_cfg[17].pin);
        }

        last_stream_status = curr_stream_status;
        curr_stream_status = "";
    }

    if (true == change_flag) {
        // don't update any further leds when nothing has changed

        for (unsigned int i = 0; i < sizeof(btn_classes)/sizeof(struct button_classes_s); i++) {
            if (
                NULL == btn_classes[i].selected_button
                || (const buttons_s *)&btn_take == btn_classes[i].button_group
                || (const buttons_s *)&btn_stream == btn_classes[i].button_group
            ) {
                // if no button has been selected yet
                // or if the button class is "btn_take"
                // or if the button class is "btn_stream"
                continue;
            }

            buttons_s button;
            memcpy_P(&button, btn_classes[i].selected_button, sizeof(buttons_s));
            mcp_io_cfg_s led_cfg;
            memcpy_P(&led_cfg, button.mating_led, sizeof(mcp_io_cfg_s));

            uint16_t *mcp_gpios;
            if (&mcp1 == led_cfg.mcp_number) {
                mcp_gpios = &mcp1_gpios;
            } else if (&mcp2 == led_cfg.mcp_number) {
                mcp_gpios = &mcp2_gpios;
            }

            *mcp_gpios = *mcp_gpios | (1 << led_cfg.pin);
        }
    }

    sei();
    mcp1.writeGPIOAB(mcp1_gpios);
    mcp2.writeGPIOAB(mcp2_gpios);
    cli();
}

void request_stream_state(void) {
    // request current stream state (this is async)
    Serial.println("get_stream_status");
}

// https://www.arduino.cc/en/Reference/SerialEvent
void serialEvent(void) {
    while (Serial.available()) {
        curr_stream_status += (char)Serial.read();
    }
}

void loop() {
    // check whether take button was pressed
    if (NULL != btn_classes[3].selected_button) {
        Serial.print("set_videos_and_composite ");
        if ("fullscreen" == btn_classes[0].selected_button->cmd_string) {
            // source a
            Serial.print(btn_classes[1].selected_button->cmd_string);
            // source b
            Serial.print(" * ");
        } else {
            // source a
            Serial.print(btn_classes[1].selected_button->cmd_string);
            Serial.print(" ");
            // source b
            Serial.print(btn_classes[2].selected_button->cmd_string);
            Serial.print(" ");
        }
        // composition mode
        Serial.println(btn_classes[3].selected_button->cmd_string);

        // reset take button state
        btn_classes[3].selected_button = NULL;
    }

    // check whether stream_state button was pressed
    if (NULL != btn_classes[4].selected_button) {
        if (last_stream_status.startsWith("stream_status live")) {
            Serial.println("set_stream_blank pause");
        } else {
            Serial.println("set_stream live");
        }

        // reset stream_state button state
        btn_classes[4].selected_button = NULL;
    }

    stream_state_timer.update();
}
