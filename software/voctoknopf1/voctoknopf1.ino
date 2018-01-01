#include <Wire.h>
#include "Adafruit_MCP23017.h"

/*
 TODO: Ethernet
       TCP
       Kommunikation mit dem Voctocore
       StreamOn

  Hardware frontend for Voctomix
  https://github.com/voc/voctomix
  created 9. Nov 2017
  last changed 25. December 2017

  With help from
  http://www.arduino.cc/en/Tutorial/ButtonStateChange
  and many friends

wenn man den voctocore fragt get_config antwortet er ngefähr sowas
"server_config {"DEFAULT":
{}, "mix": {"videocaps": "video/x-raw,format=I420,width=960,
height=540,framerate=25/1,pixel-aspect-ratio=1/1,
interlace-mode=progressive", "audiocaps": "audio/x-raw,format=S16LE,
channels=2,layout=interleaved,rate=48000",
"sources": "cam1,cam2,cam3,slides", "kind": "img", "imguri":
"file:///home/sophie/Documents/rollout/background.png"},
"output-buffers": {"mix_out": "10000"}, "fullscreen": {},
"side-by-side-equal": {}, "side-by-side-preview":
{"asize": "800x450", "apos": "12/12", "bsize": "320x180", "bpos":
"640/360"}, "picture-in-picture": {"pipsize": "320x180", "pippos":
"640/360"}, "previews": {"enabled": "false", "deinterlace": "false"},
"stream-blanker": {"enabled": "true", "sources": "pause", "volume":
"1.0", "kind": "img", "imguri":
"file:///home/sophie/Documents/rollout/background.png"},
"mirrors": {"enabled": "true"}}"
Da kann man sehen wie die chanels heißen etc.
*/

Adafruit_MCP23017 mcp1; // Create MCP 1
Adafruit_MCP23017 mcp2; // Create MCP 2

// pin mapping
const int button_fullscreen = 8;
const int led_fullscreen = 9;
const int button_side_by_side_preview = 10;
const int led_side_by_side_preview = 11;
const int button_picture_in_picture = 12;
const int led_picture_in_picture = 13;
const int button_slides_a = 14;
const int led_slides_a = 15;
const int button_cam1_a = 0;
const int led_cam1_a = 1;
const int button_cam2_a = 2;
const int led_cam2_a = 3;
const int button_cam3_a = 4;
const int led_cam3_a = 5;
const int button_slides_b = 8;
const int led_slides_b = 9;
const int button_cam1_b = 10;
const int led_cam1_b = 11;
const int button_cam2_b = 12;
const int led_cam2_b = 13;
const int button_cam3_b = 14;
const int led_cam3_b = 15;
const int button_take = 0;
const int led_take = 1;
const int button_stream = 5;
const int led_stream_red = 6;
const int led_stream_green = 7;

int buttonState = 0;                    // current state of a button
int lastButtonState_fullscreen = 0;     // previous state of each button
int lastButtonState_side_by_side_preview = 0;
int lastButtonState_picture_in_picture = 0;
int lastButtonState_slides_a = 0;
int lastButtonState_cam1_a = 0;
int lastButtonState_cam2_a = 0;
int lastButtonState_cam3_a = 0;
int lastButtonState_slides_b = 0;
int lastButtonState_cam1_b = 0;
int lastButtonState_cam2_b = 0;
int lastButtonState_cam3_b = 0;
int lastButtonState_take = 0;
int lastButtonState_stream = 0;

String video_a = "slides";           // building blocks for take-message
String video_b = "cam1";
String composite_mode = "side_by_side_preview";

String stream_status;

void setup() {

  mcp1.begin(0);      // Start MCP 1 on Hardware address 0x20
  mcp2.begin(1);      // Start MCP 2 on Hardware address 0x21

  // initialize the button pins as input:
  mcp1.pinMode(button_fullscreen, INPUT);
  mcp1.pinMode(button_side_by_side_preview, INPUT);
  mcp1.pinMode(button_picture_in_picture, INPUT);
  mcp1.pinMode(button_slides_a, INPUT);
  mcp1.pinMode(button_cam1_a, INPUT);
  mcp1.pinMode(button_cam2_a, INPUT);
  mcp1.pinMode(button_cam3_a, INPUT);
  mcp2.pinMode(button_slides_b, INPUT);
  mcp2.pinMode(button_cam1_b, INPUT);
  mcp2.pinMode(button_cam2_b, INPUT);
  mcp2.pinMode(button_cam3_b, INPUT);
  mcp2.pinMode(button_take, INPUT);
  pinMode(button_stream, INPUT);

  // initialize the LEDs as output:
  mcp1.pinMode(led_fullscreen, OUTPUT);
  mcp1.pinMode(led_side_by_side_preview, OUTPUT);
  mcp1.pinMode(led_picture_in_picture, OUTPUT);
  mcp1.pinMode(led_slides_a, OUTPUT);
  mcp1.pinMode(led_cam1_a, OUTPUT);
  mcp1.pinMode(led_cam2_a, OUTPUT);
  mcp1.pinMode(led_cam3_a, OUTPUT);
  mcp2.pinMode(led_slides_b, OUTPUT);
  mcp2.pinMode(led_cam1_b, OUTPUT);
  mcp2.pinMode(led_cam2_b, OUTPUT);
  mcp2.pinMode(led_cam3_b, OUTPUT);
  mcp2.pinMode(led_take, OUTPUT);
  pinMode(led_stream_red, OUTPUT);
  pinMode(led_stream_green, OUTPUT);

  // initialize serial communication:
  Serial.begin(9600);
  Serial.println("get_stream_status");    // Stream on?

  // test LEDs
  mcp1.digitalWrite(led_fullscreen, HIGH);
  mcp1.digitalWrite(led_side_by_side_preview, HIGH);
  mcp1.digitalWrite(led_picture_in_picture, HIGH);
  mcp1.digitalWrite(led_slides_a, HIGH);
  mcp1.digitalWrite(led_cam1_a, HIGH);
  mcp1.digitalWrite(led_cam2_a, HIGH);
  mcp1.digitalWrite(led_cam3_a, HIGH);
  mcp2.digitalWrite(led_slides_b, HIGH);
  mcp2.digitalWrite(led_cam1_b, HIGH);
  mcp2.digitalWrite(led_cam2_b, HIGH);
  mcp2.digitalWrite(led_cam3_b, HIGH);
  mcp2.digitalWrite(led_take, HIGH);
  digitalWrite(led_stream_red, HIGH);
  digitalWrite(led_stream_green, HIGH);
  delay(1000);
    /*
because of:
String video_a = "slides";
String video_b = "cam1";
String composite_mode = "side_by_side_preview";
keep some buttons illuminated:
*/
  mcp1.digitalWrite(led_fullscreen, LOW);
  mcp1.digitalWrite(led_picture_in_picture, LOW);
  mcp1.digitalWrite(led_cam1_a, LOW);
  mcp1.digitalWrite(led_cam2_a, LOW);
  mcp1.digitalWrite(led_cam3_a, LOW);
  mcp2.digitalWrite(led_slides_b, LOW);
  mcp2.digitalWrite(led_cam2_b, LOW);
  mcp2.digitalWrite(led_cam3_b, LOW);
  digitalWrite(led_stream_red, LOW);
  digitalWrite(led_stream_green, LOW);
}


void loop() {
                                                    // OnButtonPush
  // fullscreen
  buttonState = mcp1.digitalRead(button_fullscreen);    // read the pushbutton input pin
  if (buttonState != lastButtonState_fullscreen) { // compare to lastButtonState
    if (buttonState == HIGH) {
                                               // if the current state is LOW, then
      composite_mode = "fullscreen";               // the button just got pushed
      //Serial.println("composite_mode fullscreen selected");  // and things happen
      mcp1.digitalWrite(led_fullscreen, HIGH);
      mcp1.digitalWrite(led_side_by_side_preview, LOW);
      mcp1.digitalWrite(led_picture_in_picture, LOW);
    }
    else {                                         // do nothing / placeholder
    }
    delay(1);                                      // delay bit to avoid bouncing
  }
  lastButtonState_fullscreen = buttonState;        // save the current state as the last state,
                                                   // for next time through the loop

                                                   // end OnButtonPush

  // side-by-side-preview
  buttonState = mcp1.digitalRead(button_side_by_side_preview);
  if (buttonState != lastButtonState_side_by_side_preview) {
    if (buttonState == HIGH) {
      composite_mode = "side_by_side_preview";
      //Serial.println("composite_mode side_by_side_preview selected");
      mcp1.digitalWrite(led_side_by_side_preview, HIGH);
      mcp1.digitalWrite(led_fullscreen, LOW);
      mcp1.digitalWrite(led_picture_in_picture, LOW);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_side_by_side_preview = buttonState;

  // picture_in_picture
  buttonState = mcp1.digitalRead(button_picture_in_picture);
  if (buttonState != lastButtonState_picture_in_picture) {
    if (buttonState == HIGH) {
      composite_mode = "picture_in_picture";
      //Serial.println("composite_mode picture_in_picture selected");
      mcp1.digitalWrite(led_picture_in_picture, HIGH);
      mcp1.digitalWrite(led_side_by_side_preview, LOW);
      mcp1.digitalWrite(led_fullscreen, LOW);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_picture_in_picture = buttonState;

  //slides_a
   buttonState = mcp1.digitalRead(button_slides_a);
  if (buttonState != lastButtonState_slides_a) {
    if (buttonState == HIGH) {
      video_a = "slides";
      //Serial.println("slides for channel a selected");
      mcp1.digitalWrite(led_slides_a, HIGH);
      mcp1.digitalWrite(led_cam1_a, LOW);
      mcp1.digitalWrite(led_cam2_a, LOW);
      mcp1.digitalWrite(led_cam3_a, LOW);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_slides_a = buttonState;

  //cam1_a
   buttonState = mcp1.digitalRead(button_cam1_a);
  if (buttonState != lastButtonState_cam1_a) {
    if (buttonState == HIGH) {
      video_a = "cam1";
      //Serial.println("cam1 for channel a selected");
      mcp1.digitalWrite(led_slides_a, LOW);
      mcp1.digitalWrite(led_cam1_a, HIGH);
      mcp1.digitalWrite(led_cam2_a, LOW);
      mcp1.digitalWrite(led_cam3_a, LOW);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_cam1_a = buttonState;

  //cam2_a
   buttonState = mcp1.digitalRead(button_cam2_a);
  if (buttonState != lastButtonState_cam2_a) {
    if (buttonState == HIGH) {
      video_a = "cam2";
      //Serial.println("cam2 for channel a selected");
      mcp1.digitalWrite(led_slides_a, LOW);
      mcp1.digitalWrite(led_cam1_a, LOW);
      mcp1.digitalWrite(led_cam2_a, HIGH);
      mcp1.digitalWrite(led_cam3_a, LOW);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_cam2_a = buttonState;

    //cam3_a
   buttonState = mcp1.digitalRead(button_cam3_a);
  if (buttonState != lastButtonState_cam3_a) {
    if (buttonState == HIGH) {
      video_a = "cam3";
      //Serial.println("cam3 for channel a selected");
      mcp1.digitalWrite(led_slides_a, LOW);
      mcp1.digitalWrite(led_cam1_a, LOW);
      mcp1.digitalWrite(led_cam2_a, LOW);
      mcp1.digitalWrite(led_cam3_a, HIGH);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_cam3_a = buttonState;

  //slides_b
   buttonState = mcp2.digitalRead(button_slides_b);
  if (buttonState != lastButtonState_slides_b) {
    if (buttonState == HIGH) {
      video_b = "slides";
      //Serial.println("slides for channel b selected");
      mcp2.digitalWrite(led_slides_b, HIGH);
      mcp2.digitalWrite(led_cam1_b, LOW);
      mcp2.digitalWrite(led_cam2_b, LOW);
      mcp2.digitalWrite(led_cam3_b, LOW);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_slides_b = buttonState;

  //cam1_b
   buttonState = mcp2.digitalRead(button_cam1_b);
  if (buttonState != lastButtonState_cam1_b) {
    if (buttonState == HIGH) {
      video_b = "cam1";
      //Serial.println("cam1 for channel b selected");
      mcp2.digitalWrite(led_slides_b, LOW);
      mcp2.digitalWrite(led_cam1_b, HIGH);
      mcp2.digitalWrite(led_cam2_b, LOW);
      mcp2.digitalWrite(led_cam3_b, LOW);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_cam1_b = buttonState;

  //cam2_b
   buttonState = mcp2.digitalRead(button_cam2_b);
  if (buttonState != lastButtonState_cam2_b) {
    if (buttonState == HIGH) {
      video_b = "cam2";
      //Serial.println("cam2 for channel b selected");
      mcp2.digitalWrite(led_slides_b, LOW);
      mcp2.digitalWrite(led_cam1_b, LOW);
      mcp2.digitalWrite(led_cam2_b, HIGH);
      mcp2.digitalWrite(led_cam3_b, LOW);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_cam2_b = buttonState;

  //cam3_b
   buttonState = mcp2.digitalRead(button_cam3_b);
  if (buttonState != lastButtonState_cam3_b) {
    if (buttonState == HIGH) {
      video_b = "cam3";
      //Serial.println("cam3 for channel b selected");
      mcp2.digitalWrite(led_slides_b, LOW);
      mcp2.digitalWrite(led_cam1_b, LOW);
      mcp2.digitalWrite(led_cam2_b, LOW);
      mcp2.digitalWrite(led_cam3_b, HIGH);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_cam3_b = buttonState;

  //take
   buttonState = mcp2.digitalRead(button_take);
  if (buttonState != lastButtonState_take) {
    if (buttonState == HIGH) {
      if(composite_mode == "fullscreen") {
         Serial.println("set_videos_and_composite " + video_a + " * " + composite_mode);
      }
      else
      Serial.println("set_videos_and_composite " + video_a + " " + video_b + " " + composite_mode);
      mcp2.digitalWrite(led_take, HIGH);
    }
    else {
    }
    delay(1);
  }
  lastButtonState_take = buttonState;      //dann fragen ob message angekommen ist, dann LED LOW


  //stream_on

  stream_status = Serial.read();
  if (stream_status == "stream_status live") {
      digitalWrite(led_stream_red, LOW);
      digitalWrite(led_stream_green, HIGH);
    }
    else {
      digitalWrite(led_stream_red, HIGH);
      digitalWrite(led_stream_green, LOW);
    }
//

    buttonState = digitalRead(button_stream);      //OnButtonPush
   if (buttonState != lastButtonState_stream) {
    if (buttonState == HIGH) {
          if (stream_status == "> stream_status live") {
              Serial.println("set_stream_blank pause");
              digitalWrite(led_stream_red, HIGH);
              digitalWrite(led_stream_green, LOW);
              }
          else {
              Serial.println("set_stream live");
              digitalWrite(led_stream_red, LOW);
              digitalWrite(led_stream_green, HIGH);
            }
    }
    else {
    }
    delay(1);
  }

  lastButtonState_stream = buttonState;

}
