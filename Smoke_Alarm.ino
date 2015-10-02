const int gasPin = A0;                                             // gas pin Arduino analog A0
int smoke_level;

int led_G = 11;                                                    // the pin that the LED is attached to
int led_W = 10;
int led_D = 9;

int speakerOUT = 6;


                                                                  // the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);                                             // Initalize serial port - 9600 bps
  
  pinMode(gasPin, INPUT);
  
  pinMode(led_G, OUTPUT);
  pinMode(led_W, OUTPUT);
  pinMode(led_D, OUTPUT);
  pinMode(speakerOUT, OUTPUT);
}

void loop() {
  
  smoke_level= analogRead(gasPin);                                 //arduino reads the value from the smoke sensor
  Serial.println(smoke_level);                                    //prints just for debugging purposes, to see what values the sensor is picking up

  if(smoke_level > 42){                                            //Warning state - Light loop & Sound Ping
     for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(led_W, fadeValue);         
    delay(30);                            
    } 

  // fade out from max to min in increments of 5 points:
    for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(led_W, fadeValue);         
    delay(30);                            
    } 

    tone(6, 523, 300);
    delay(300);

    digitalWrite(led_D,LOW);
    digitalWrite(led_G,LOW);      
    } 
  
  
    if(smoke_level > 80){                                            //Danger state - Light loop & Sound Ping
     for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
      analogWrite(led_D, fadeValue);         
      delay(10);                            
    } 

  // fade out from max to min in increments of 5 points:
    for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
      analogWrite(led_D, fadeValue);         
      delay(10);                            
    } 

    tone(6, 523, 300);
    delay(100);

    digitalWrite(led_W,LOW);
    digitalWrite(led_G,LOW);      
    } 
    
    
  else{                                        //All Clear State
    digitalWrite(led_G,HIGH);
    tone(6, 523, 300);
    delay(3000); 
    
    digitalWrite(led_W,LOW);
    digitalWrite(led_D,LOW);  
  }
  
}





// Goal create a wanring alarm for smoke 