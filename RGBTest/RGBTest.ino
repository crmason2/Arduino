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
  rgbColour[0] = MAX;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  digitalWrite(PIN_TRAN, HIGH);

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < MAX; i += 1) {
//      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(DELAY);
    }
    
    // cross-fade the two colours.
    for(int i = 0; i < MAX; i += 1) {
      rgbColour[decColour] -= 1;
//      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(DELAY);
    }
  }
  digitalWrite(PIN_TRAN, LOW);
  delay(5000);
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(PIN_RED, red);
  analogWrite(PIN_GREEN, green);
  analogWrite(PIN_BLUE, blue);
 }
