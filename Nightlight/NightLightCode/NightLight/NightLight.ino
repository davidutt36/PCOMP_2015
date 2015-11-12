// Pins
int sensorPin = A0;
int lightPin = 9;

// Variables
int lightState = 0;
int lowThreshold = 400;
int highTreshold = 600;
float startTime = 0;
float currentTime = 0;
boolean flag = false;
boolean night = false;  // if false it is a day, and if true it is a night
void setup() {
  
  // Start Serial & set pin to output	
  Serial.begin(9600);
  delay(100);
  pinMode(lightPin,OUTPUT);
  
}

void loop() {

  // Read the sensor pin
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  //Serial.println()
  int interval = 3000;
  unsigned long time;
  
  
    if (sensorValue < lowThreshold){
      night = true;
    }else{
      night = false ;
      startTime = 0;
      flag = false;
    }
  if( !night ){
    
    digitalWrite(lightPin,LOW);
  }else if( night ){
    if( !flag ) {
    startTime = millis();
    flag = true;
    }
    currentTime = millis();
    
    if( currentTime - startTime < 6000 ){
      digitalWrite(lightPin,HIGH);
    }else{
      digitalWrite(lightPin,LOW);
    }
    
  
  }
  // If light level is low is detected, switch light on

  
/*  // If light level goes up again, switch the lights off
  if (sensorValue > highTreshold){ 
    digitalWrite(lightPin, LOW);
  } */
}


//
