#include <Wire.h>
#include <Adafruit_MCP23017.h>

Adafruit_MCP23017 mcp1; // Create MCP 1
Adafruit_MCP23017 mcp2; // Create MCP 2

void setup() {  
  mcp1.begin(0);      // Start MCP 1 on Hardware address 0x20
  mcp2.begin(1);      // Start MCP 2 on Hardware address 0x21

  mcp1.pinMode(7, INPUT); // Define GPA7 on MCP1 as input
  mcp1.pullUp(7, HIGH);  // Activate Internal Pull-Up Resistor

  mcp1.pinMode(8, OUTPUT); // Define GPB0 on MCP1 as Output
  mcp2.pinMode(15, OUTPUT); // Define GPB7 on MCP2 as Output

} // End Setup

void loop() {
 // The LED on GPB0 will 'echo' the button on GPA7

  if (mcp1.digitalRead(7) == LOW)
  {
    mcp1.digitalWrite(8, HIGH);
    mcp2.digitalWrite(15, HIGH);
  }
  else
  {
    mcp1.digitalWrite(8, LOW);
    mcp2.digitalWrite(15, LOW);
  }
} // End loop
