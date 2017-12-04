#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>

/*
 TODO: Kommunikation mit dem Voctocore, Zeile 316
       und Stream Status abfragen etc, Zeile 326 bis Ende
 
  Hardware frontend for Voctomix
  https://github.com/voc/voctomix

  created 9 Nov 2017

  The circuit, several instances of:
  - pushbutton attached to pin from +5V
  - 10 kilohm resistor attached to pin from ground
  - LED attached from pin to ground with 220 ohm resistor
  
  Mapping, for reference
  22/23 fullscreen (button, LED)
  24/25 side_by_side_preview (...)
  26/27 picture_in_picture
  28/29 slides a
  30/31 cam1 a
  32/33 cam2 a
  34/35 cam3 a
  36/37 slides b
  38/39 cam1 b
  40/41 cam2 b
  42/43 cam3 b
  44/45 take
  46/47/48 stream (button, LED red, LED green)
  
  With help from 
  http://www.arduino.cc/en/Tutorial/ButtonStateChange

wenn man den voctocore fragt get_config antwortet er ngefähr sowas
"server_config {"DEFAULT": 
{}, "mix": {"videocaps": "video/x-raw,format=I420,width=960,
height=540,framerate=25/1,pixel-aspect-ratio=1/1,
interlace-mode=progressive", "audiocaps": "audio/x-raw,format=S16LE,
channels=2,layout=interleaved,rate=48000", 
"sources": "cam1,cam2,cam3,grabber", "kind": "img", "imguri": 
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

Da kann  men sehen wie die chanels heißen etc.
*/

// pin mapping
const int button_fullscreen = 22;
const int led_fullscreen = 23;
const int button_side_by_side_preview = 24;
const int led_side_by_side_preview = 25;
const int button_picture_in_picture = 26;
const int led_picture_in_picture = 27;
const int button_slides_a = 28;    
const int led_slides_a = 29;    
const int button_cam1_a = 30;
const int led_cam1_a = 31;
const int button_cam2_a = 32;
const int led_cam2_a = 33;
const int button_cam3_a = 34;
const int led_cam3_a = 35;
const int button_slides_b = 36;    
const int led_slides_b = 37;    
const int button_cam1_b = 38;
const int led_cam1_b = 39;
const int button_cam2_b = 40;
const int led_cam2_b = 41;
const int button_cam3_b = 42;
const int led_cam3_b = 43;
const int button_take = 44;
const int led_take = 45;
const int button_stream = 46;
const int led_stream_red = 47;
const int led_stream_green = 48;

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
String video_b = "cam_1";
String composite_mode = "side_by_side_preview";

String stream_status;

void setup() {
  
  // initialize the button pins as input:
  pinMode(button_fullscreen, INPUT);
  pinMode(button_side_by_side_preview, INPUT);
  pinMode(button_picture_in_picture, INPUT);
  pinMode(button_slides_a, INPUT);
  pinMode(button_cam1_a, INPUT);
  pinMode(button_cam2_a, INPUT);
  pinMode(button_cam3_a, INPUT);
  pinMode(button_slides_b, INPUT);
  pinMode(button_cam1_b, INPUT);
  pinMode(button_cam2_b, INPUT);
  pinMode(button_cam3_b, INPUT);
  pinMode(button_take, INPUT);
  pinMode(button_stream, INPUT);
  
  // initialize the LEDs as output:
  pinMode(led_fullscreen, OUTPUT);
  pinMode(led_side_by_side_preview, OUTPUT);
  pinMode(led_picture_in_picture, OUTPUT);
  pinMode(led_slides_a, OUTPUT);
  pinMode(led_cam1_a, OUTPUT);
  pinMode(led_cam2_a, OUTPUT);
  pinMode(led_cam3_a, OUTPUT);
  pinMode(led_slides_b, OUTPUT);
  pinMode(led_cam1_b, OUTPUT);
  pinMode(led_cam2_b, OUTPUT);
  pinMode(led_cam3_b, OUTPUT);
  pinMode(led_take, OUTPUT);
  pinMode(led_stream_red, OUTPUT);
  pinMode(led_stream_green, OUTPUT);
  
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
                                                   // OnButtonPush
  // fullscreen
  buttonState = digitalRead(button_fullscreen);    // read the pushbutton input pin
  if (buttonState != lastButtonState_fullscreen) { // compare to lastButtonState
    if (buttonState == HIGH) {
                                               // if the current state is LOW, then 
      composite_mode = "fullscreen";               // the button just got pushed
      Serial.println("composite_mode fullscreen selected");  // and things happen
      digitalWrite(led_fullscreen, HIGH);
      digitalWrite(led_side_by_side_preview, LOW);
      digitalWrite(led_picture_in_picture, LOW);
    } 
    else {                                         // do nothing / placeholder
    }
    delay(1);                                      // delay bit to avoid bouncing 
  }
  lastButtonState_fullscreen = buttonState;        // save the current state as the last state, 
                                                   // for next time through the loop
                                                   
                                                   // end OnButtonPush 

  // side-by-side-preview
  buttonState = digitalRead(button_side_by_side_preview);        
  if (buttonState != lastButtonState_side_by_side_preview) {     
    if (buttonState == HIGH) {                                          
      composite_mode = "side_by_side_preview";
      Serial.println("composite_mode side_by_side_preview selected");
      digitalWrite(led_side_by_side_preview, HIGH);
      digitalWrite(led_fullscreen, LOW);
      digitalWrite(led_picture_in_picture, LOW);                   
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_side_by_side_preview = buttonState;      

  // picture_in_picture
  buttonState = digitalRead(button_picture_in_picture);        
  if (buttonState != lastButtonState_picture_in_picture) {     
    if (buttonState == HIGH) {                                            
      composite_mode = "picture_in_picture";
      Serial.println("composite_mode picture_in_picture selected");
      digitalWrite(led_picture_in_picture, HIGH);
      digitalWrite(led_side_by_side_preview, LOW);
      digitalWrite(led_fullscreen, LOW);                  
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_picture_in_picture = buttonState;       

  //slides_a
   buttonState = digitalRead(button_slides_a);        
  if (buttonState != lastButtonState_slides_a) {     
    if (buttonState == HIGH) {                                            
      video_a = "slides";
      Serial.println("slides for channel a selected");
      digitalWrite(led_slides_a, HIGH);
      digitalWrite(led_cam1_a, LOW);
      digitalWrite(led_cam2_a, LOW);
      digitalWrite(led_cam3_a, LOW);                        
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_slides_a = buttonState;   

  //cam1_a
   buttonState = digitalRead(button_cam1_a);        
  if (buttonState != lastButtonState_cam1_a) {     
    if (buttonState == HIGH) {                                            
      video_a = "cam1";
      Serial.println("cam1 for channel a selected");
      digitalWrite(led_slides_a, LOW);
      digitalWrite(led_cam1_a, HIGH);
      digitalWrite(led_cam2_a, LOW);
      digitalWrite(led_cam3_a, LOW);                        
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_cam1_a = buttonState;  
  
  //cam2_a
   buttonState = digitalRead(button_cam2_a);        
  if (buttonState != lastButtonState_cam2_a) {     
    if (buttonState == HIGH) {                                            
      video_a = "cam2";
      Serial.println("cam2 for channel a selected");
      digitalWrite(led_slides_a, LOW);
      digitalWrite(led_cam1_a, LOW);
      digitalWrite(led_cam2_a, HIGH);
      digitalWrite(led_cam3_a, LOW);                        
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_cam2_a = buttonState; 

    //cam3_a
   buttonState = digitalRead(button_cam3_a);        
  if (buttonState != lastButtonState_cam3_a) {     
    if (buttonState == HIGH) {                                            
      video_a = "cam3";
      Serial.println("cam3 for channel a selected");
      digitalWrite(led_slides_a, LOW);
      digitalWrite(led_cam1_a, LOW);
      digitalWrite(led_cam2_a, LOW);
      digitalWrite(led_cam3_a, HIGH);                        
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_cam3_a = buttonState;   
  
  //slides_b
   buttonState = digitalRead(button_slides_b);        
  if (buttonState != lastButtonState_slides_b) {     
    if (buttonState == HIGH) {                                            
      video_b = "slides";
      Serial.println("slides for channel b selected");
      digitalWrite(led_slides_b, HIGH);
      digitalWrite(led_cam1_b, LOW);
      digitalWrite(led_cam2_b, LOW);
      digitalWrite(led_cam3_b, LOW);                        
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_slides_b = buttonState;   

  //cam1_b
   buttonState = digitalRead(button_cam1_b);        
  if (buttonState != lastButtonState_cam1_b) {     
    if (buttonState == HIGH) {                                            
      video_b = "cam1";
      Serial.println("cam1 for channel b selected");
      digitalWrite(led_slides_b, LOW);
      digitalWrite(led_cam1_b, HIGH);
      digitalWrite(led_cam2_b, LOW);
      digitalWrite(led_cam3_b, LOW);                        
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_cam1_b = buttonState;  
  
  //cam2_b
   buttonState = digitalRead(button_cam2_b);        
  if (buttonState != lastButtonState_cam2_b) {     
    if (buttonState == HIGH) {                                            
      video_b = "cam2";
      Serial.println("cam2 for channel b selected");
      digitalWrite(led_slides_b, LOW);
      digitalWrite(led_cam1_b, LOW);
      digitalWrite(led_cam2_b, HIGH);
      digitalWrite(led_cam3_b, LOW);                        
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_cam2_b = buttonState; 

  //cam3_b
   buttonState = digitalRead(button_cam3_b);        
  if (buttonState != lastButtonState_cam3_b) {     
    if (buttonState == HIGH) {                                            
      video_b = "cam3";
      Serial.println("cam3 for channel b selected");
      digitalWrite(led_slides_b, LOW);
      digitalWrite(led_cam1_b, LOW);
      digitalWrite(led_cam2_b, LOW);
      digitalWrite(led_cam3_b, HIGH);                        
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_cam3_b = buttonState;   

  //take
   buttonState = digitalRead(button_take);        
  if (buttonState != lastButtonState_take) {     
    if (buttonState == HIGH) {                                          
      Serial.println("< set_videos_and_composite " + video_a + " " + video_b + " " + composite_mode); 
      digitalWrite(led_take, HIGH);                        
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_take = buttonState; 
  //abfragen ob stream status geändert hat, dann LED LOW
  /*
  stream
  stream_status =       ;   // muss noch gemacht werden !! 
                            // < get_stream_status
                            // Frage: wie oft kann man den Voctocore das fragen 
                            // ohne dass er genervt ist?
  if (stream_status == live) {   
      digitalWrite(led_stream_red, LOW);
      digitalWrite(led_stream_green, HIGH);  
    } 
    else {
      digitalWrite(led_stream_red, HIGH);
      digitalWrite(led_stream_green, LOW);  
    }
   
    buttonState = digitalRead(button_stream);      //OnButtonPush
   if (buttonState != lastButtonState_stream) {     
    if (buttonState == HIGH) {   
          if (stream_status == live) {       
              Serial.println("<set_stream_blank pause");
              digitalWrite(led_stream_red, HIGH);
              digitalWrite(led_stream_green, LOW);              
              } 
          else {
              Serial.println("set_stream_live");
              digitalWrite(led_stream_red, LOW);
              digitalWrite(led_stream_green, HIGH);
            }                     
    } 
    else {
    }
    delay(1);                         
  }
  lastButtonState_stream = buttonState; 
*/
}
