int ledPin = 6; // choose the pin for the LED
int inPin = 5;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inPin, INPUT);    // declare pushbutton as input
  Serial.begin(9600);
  Serial.println("Hello, world?");
}

void loop(){
  val = digitalRead(inPin);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin, LOW);  // turn LED OFF
    Serial.println("pushed");
  } else {
    digitalWrite(ledPin, HIGH);  // turn LED ON
  }
}

