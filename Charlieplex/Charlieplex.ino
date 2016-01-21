byte LED_PIN_X0 = 10;
byte LED_PIN_X1 = 11;
byte LED_PIN_Y0 = 12;
byte LED_PIN_Y1 = 13;
int DELAY = 20;

void setup()
{
  pinMode(LED_PIN_X0, INPUT);
  digitalWrite(LED_PIN_X0, LOW);
  pinMode(LED_PIN_X1, INPUT);
  digitalWrite(LED_PIN_X1, LOW);
  pinMode(LED_PIN_Y0, INPUT);
  digitalWrite(LED_PIN_Y0, LOW);
  pinMode(LED_PIN_Y1, INPUT);
  digitalWrite(LED_PIN_Y1, LOW);
}

void loop()
{
  pinMode(LED_PIN_Y1, OUTPUT);
  digitalWrite(LED_PIN_Y1, HIGH);
  pinMode(LED_PIN_X1, OUTPUT);
  digitalWrite(LED_PIN_X1, LOW);
  delay(DELAY);
  pinMode(LED_PIN_Y1, INPUT);
  pinMode(LED_PIN_X1, INPUT);
  
  pinMode(LED_PIN_Y1, OUTPUT);
  digitalWrite(LED_PIN_Y1, HIGH);
  pinMode(LED_PIN_X0, OUTPUT);
  digitalWrite(LED_PIN_X0, LOW);
  delay(DELAY);
  pinMode(LED_PIN_Y1, INPUT);
  pinMode(LED_PIN_X0, INPUT);

  pinMode(LED_PIN_X1, OUTPUT);
  digitalWrite(LED_PIN_X1, HIGH);
  pinMode(LED_PIN_Y1, OUTPUT);
  digitalWrite(LED_PIN_Y1, LOW);
  delay(DELAY);
  pinMode(LED_PIN_X1, INPUT);
  pinMode(LED_PIN_Y1, INPUT);

  pinMode(LED_PIN_X0, OUTPUT);
  digitalWrite(LED_PIN_X0, HIGH);
  pinMode(LED_PIN_Y1, OUTPUT);
  digitalWrite(LED_PIN_Y1, LOW);
  delay(DELAY);
  pinMode(LED_PIN_X0, INPUT);
  pinMode(LED_PIN_Y1, INPUT);
  
  pinMode(LED_PIN_Y0, OUTPUT);
  digitalWrite(LED_PIN_Y0, HIGH);
  pinMode(LED_PIN_X1, OUTPUT);
  digitalWrite(LED_PIN_X1, LOW);
  delay(DELAY);
  pinMode(LED_PIN_Y0, INPUT);
  pinMode(LED_PIN_X1, INPUT);
  
  pinMode(LED_PIN_Y0, OUTPUT);
  digitalWrite(LED_PIN_Y0, HIGH);
  pinMode(LED_PIN_X0, OUTPUT);
  digitalWrite(LED_PIN_X0, LOW);
  delay(DELAY);
  pinMode(LED_PIN_Y0, INPUT);
  pinMode(LED_PIN_X0, INPUT);

  pinMode(LED_PIN_X1, OUTPUT);
  digitalWrite(LED_PIN_X1, HIGH);
  pinMode(LED_PIN_Y0, OUTPUT);
  digitalWrite(LED_PIN_Y0, LOW);
  delay(DELAY);
  pinMode(LED_PIN_X1, INPUT);
  pinMode(LED_PIN_Y0, INPUT);

  pinMode(LED_PIN_X0, OUTPUT);
  digitalWrite(LED_PIN_X0, HIGH);
  pinMode(LED_PIN_Y0, OUTPUT);
  digitalWrite(LED_PIN_Y0, LOW);
  delay(DELAY);
  pinMode(LED_PIN_X0, INPUT);
  pinMode(LED_PIN_Y0, INPUT);
  
  pinMode(LED_PIN_Y1, OUTPUT);
  digitalWrite(LED_PIN_Y1, HIGH);
  pinMode(LED_PIN_Y0, OUTPUT);
  digitalWrite(LED_PIN_Y0, LOW);
  delay(DELAY);
  pinMode(LED_PIN_Y1, INPUT);
  pinMode(LED_PIN_Y0, INPUT);
  
  pinMode(LED_PIN_Y0, OUTPUT);
  digitalWrite(LED_PIN_Y0, HIGH);
  pinMode(LED_PIN_Y1, OUTPUT);
  digitalWrite(LED_PIN_Y1, LOW);
  delay(DELAY);
  pinMode(LED_PIN_Y0, INPUT);
  pinMode(LED_PIN_Y1, INPUT);

  pinMode(LED_PIN_X1, OUTPUT);
  digitalWrite(LED_PIN_X1, HIGH);
  pinMode(LED_PIN_X0, OUTPUT);
  digitalWrite(LED_PIN_X0, LOW);
  delay(DELAY);
  pinMode(LED_PIN_X1, INPUT);
  pinMode(LED_PIN_X0, INPUT);

  pinMode(LED_PIN_X0, OUTPUT);
  digitalWrite(LED_PIN_X0, HIGH);
  pinMode(LED_PIN_X1, OUTPUT);
  digitalWrite(LED_PIN_X1, LOW);
  delay(DELAY);
  pinMode(LED_PIN_X0, INPUT);
  pinMode(LED_PIN_X1, INPUT);
}
