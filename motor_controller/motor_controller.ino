

const int dirPin = 4;  
const int stepPin = 5;  
const int stepsPerRevolution = 800;  
  
void setup()  
{  
    pinMode(stepPin, OUTPUT);  
    pinMode(dirPin, OUTPUT);
    digitalWrite(stepPin, LOW);
    digitalWrite(dirPin ,LOW); 
}  
void loop()  
{  
    digitalWrite(dirPin, HIGH);  
    for(int x = 0; x < stepsPerRevolution; x++)  
    {  
        digitalWrite(stepPin, HIGH);  
        delayMicroseconds(2000);  
        digitalWrite(stepPin, LOW);  
        delayMicroseconds(2000);  
    }  
    delay(1000);   
      
    digitalWrite(dirPin, LOW);  
    for(int x = 0; x < stepsPerRevolution; x++)  
    {  
        digitalWrite(stepPin, HIGH);  
        delayMicroseconds(2000);  
        digitalWrite(stepPin, LOW);  
        delayMicroseconds(2000);  
    }  
    delay(1000);   
}  
