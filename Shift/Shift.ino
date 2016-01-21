byte PIN_SRCLR = 2;
byte PIN_SRCLK = 3;
byte PIN_RCLK = 4;
byte PIN_OE = 6;
byte PIN_SER = 7;
byte PIN_CHAR = 8;

void setup()
{
  pinMode(PIN_SRCLR, OUTPUT);
  pinMode(PIN_SRCLK, OUTPUT);
  pinMode(PIN_RCLK, OUTPUT);
  pinMode(PIN_OE, OUTPUT);
  pinMode(PIN_SER, OUTPUT);
  pinMode(PIN_CHAR, OUTPUT);
  
  digitalWrite(PIN_OE, LOW);
  digitalWrite(PIN_SRCLR, LOW);
  digitalWrite(PIN_RCLK, HIGH);
  digitalWrite(PIN_RCLK, LOW);
  digitalWrite(PIN_SRCLR, HIGH);
}

void loop()
{
  writeSerial(HIGH);
  writeSerial(LOW);
  writeSerial(HIGH);
  writeSerial(LOW);
  writeSerial(HIGH);
  writeSerial(LOW);
  writeSerial(HIGH);
  writeSerial(LOW);
  digitalWrite(PIN_CHAR, HIGH);
  digitalWrite(PIN_RCLK, HIGH);
  digitalWrite(PIN_RCLK, LOW);
  delay(500);
//  digitalWrite(PIN_CHAR, LOW);
//  delay(500);
//  writeSerial(LOW);
//  writeSerial(HIGH);
//  writeSerial(LOW);
//  writeSerial(HIGH);
//  writeSerial(LOW);
//  writeSerial(HIGH);
//  writeSerial(LOW);
//  writeSerial(HIGH);
//  digitalWrite(PIN_CHAR, HIGH);
//  digitalWrite(PIN_RCLK, HIGH);
//  digitalWrite(PIN_RCLK, LOW);
//  delay(500);
//  digitalWrite(PIN_CHAR, LOW);
//  delay(500);
}

void writeSerial(boolean level)
{
  digitalWrite(PIN_SER, level);
  digitalWrite(PIN_SRCLK, HIGH);
  digitalWrite(PIN_SRCLK, LOW);
}
