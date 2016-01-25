#include <avr/wdt.h>
#define INPUT_SIZE 25
#define RED_MAX 255
#define GREEN_MAX 110
#define BLUE_MAX 95
#define MAX 255
#define TRAN_COUNT 5
#define DELAY 2

byte PIN_RED[2] = {9,3};
byte PIN_GREEN[2] = {10,5};
byte PIN_BLUE[2] = {11,6};
byte PIN_TRAN[5] = {13,12,8,7,2};
byte TYPE = 2;
unsigned int rgbColor[6] = {255,0,0,0,0,255};

void setup() {
  wdt_disable();
  setColorRGB(rgbColor[0], rgbColor[1], rgbColor[2]);
  for(byte i = 0; i < TRAN_COUNT; i++) {
    digitalWrite(PIN_TRAN[i], LOW);
  }
  Serial.begin(9600);
  while(!Serial){;}
}

void loop() {

  readInput();
  if(TYPE == 1) {
    serialType();
  }
  else if(TYPE == 2) {
    fadeType();
  }
  else if(TYPE == 3) {
    gradientType();
  }
}

void serialType() {
  //Serial
  setColorRGB(rgbColor[0], rgbColor[1], rgbColor[2]);
  for(byte i = 0; i < TRAN_COUNT; i++) {
    turnOn(i);
  }
}

void fadeType() {
  //Fade
  rgbColor[0] = MAX;
  rgbColor[1] = 0;
  rgbColor[2] = 0;
  
  //Choose the colors to increment and decrement.
  for (int decColor = 0; decColor < 3; decColor += 1) {
    int incColor = decColor == 2 ? 0 : decColor + 1;

    //Cross-fade
    for(int i = 0; i < MAX; i++) {
      rgbColor[incColor]++;
      setColorRGB(rgbColor[0], rgbColor[1], rgbColor[2]);
      for(byte i = 0; i < TRAN_COUNT; i++) {
        turnOn(i);
      }
    }
    
    //Cross-fade
    for(int i = 0; i < MAX; i++) {
      rgbColor[decColor]--;
      setColorRGB(rgbColor[0], rgbColor[1], rgbColor[2]);
      for(byte i = 0; i < TRAN_COUNT; i++) {
        turnOn(i);
      }
    }
  }
}

void gradientType() {
  for(byte i = 0; i < TRAN_COUNT; i++) {
    setColorRGB(gradientCalc(rgbColor[0], rgbColor[3], i * 2), gradientCalc(rgbColor[1], rgbColor[4], i * 2), gradientCalc(rgbColor[2], rgbColor[5], i * 2), 0);
    setColorRGB(gradientCalc(rgbColor[0], rgbColor[3], (i * 2) + 1), gradientCalc(rgbColor[1], rgbColor[4], (i * 2) + 1), gradientCalc(rgbColor[2], rgbColor[5], (i * 2) + 1), 1);
    turnOn(i);
  }
}

byte gradientCalc(byte c1, byte c2, byte i) {
  return (c1 + (((c2 - c1) / ((TRAN_COUNT * 2) - 1)) * i));
}

void setColorRGB(unsigned int red, unsigned int green, unsigned int blue) {
  setColorRGB(red, green, blue, 0);
  setColorRGB(red, green, blue, 1);
}

void setColorRGB(unsigned int red, unsigned int green, unsigned int blue, byte i) {
  analogWrite(PIN_RED[i], map(constrain(red, 0, MAX), 0, MAX, 0, RED_MAX));
  analogWrite(PIN_GREEN[i], map(constrain(green, 0, MAX), 0, MAX, 0, GREEN_MAX));
  analogWrite(PIN_BLUE[i], map(constrain(blue, 0, MAX), 0, MAX, 0, BLUE_MAX));
}

void readInput() {
  while(Serial.available() > 0) {
    
    char input[INPUT_SIZE+1];
    byte size = Serial.readBytes(input, INPUT_SIZE);
    input[size] = 0;

    Serial.print("Received: ");
    Serial.println(input);
    
    char* type = strtok(input, ":");
    
    if(type == 0 || type == NULL) {
      Serial.println("Invalid type");
      return;
    }
    
    byte typeb = atoi(type);
    
    if(typeb > 3) {
      Serial.println("Invalid type");
      return;
    }
        
    if(typeb == 1 || typeb == 3) {
      if(!readColor(0)) {
        return;
      }
      if(typeb == 3) {
        if(!readColor(3)) {
          return;
        }
      }
    }
    
    TYPE = typeb;
  }
}

boolean readColor(byte shift)
{
  char* red = strtok(0, ",");
  char* green = strtok(0, ",");
  char* blue = strtok(0, ",");
  
  if(red == 0 || red == NULL || green == 0 || green == NULL || blue == 0 || blue == NULL) {
    Serial.println("Invalid colors");
    return false;
  }
  
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" Green: ");
  Serial.print(green);
  Serial.print(" Blue: ");
  Serial.println(blue);
  
  rgbColor[0 + shift] = atoi(red);
  rgbColor[1 + shift] = atoi(green);
  rgbColor[2 + shift] = atoi(blue);
  
  return true;
}

void turnOn(byte index)
{
  //byte previous = (index < TRAN_COUNT) ? index : 0;
  digitalWrite(PIN_TRAN[index], HIGH);
  delay(DELAY);
  digitalWrite(PIN_TRAN[index], LOW);
}
