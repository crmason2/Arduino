byte PIN_RED = 9;
byte PIN_GREEN = 11;
byte PIN_BLUE = 10;
byte PIN_TRAN = 8;
byte MAX = 125;
byte DELAY = 20;

void setup() {
  setColourRgb(0,0,0);
  digitalWrite(PIN_TRAN, LOW);
}

void loop() {
  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 0;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  
  setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
  digitalWrite(PIN_TRAN, HIGH);
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(PIN_RED, red);
  analogWrite(PIN_GREEN, green);
  analogWrite(PIN_BLUE, blue);
 }
