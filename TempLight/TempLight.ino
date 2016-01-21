byte APIN_LIGHT = 0;
byte APIN_TEMP = 1;
byte PIN_RED = 3;
byte PIN_GREEN = 5;
byte PIN_BLUE = 6;
byte red = 0;
int interval = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop()
{
  int temp = analogRead(APIN_TEMP);
  int light = analogRead(APIN_LIGHT);
  
  Serial.print(temp);
  Serial.print(",");
  Serial.println(light);
  
  analogWrite(PIN_BLUE, map(temp, 0, 1023, 0, 255));
  analogWrite(PIN_GREEN, map(light, 0, 1023, 255, 0));
  analogWrite(PIN_RED, red);
  
  red += interval;
  if(red == 255)
  {
    interval = -1;
  }
  if(red == 0)
  {
    interval = 1;
  }
  
  delay(10);
}
