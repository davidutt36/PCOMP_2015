//int buttonPin = 7;
int xPin= A0;
int yPin = A1;

void setup() {
  //pinMode(buttonPin,INPUT_PULLUP); //internal resistor
  Serial.begin(9600);
}

void loop() {
//int buttonValue = digitalRead( buttonPin );
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);
    
  //Serial.print(xVal+':'+yVal+ +'n');  ___ : ____n
  //or
  Serial.print(xVal,DEC);
  Serial.print(":");
  Serial.print(yVal,DEC);
  Serial.println('n');
  
  
  delay(30);
}

