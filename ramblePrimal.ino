
int motor3_dir1 = 5;
int motor3_dir2 = 4;
int motor3_pwm  = 9;

int motor4_dir1 = 3;
int motor4_dir2 = 2;
int motor4_pwm  = 6;

const int trigPin=13;
const int echoPin=12;

void setup()
{
    Serial.begin(9600);

    pinMode(motor3_dir1,OUTPUT);
    pinMode(motor3_dir2,OUTPUT);
    pinMode(motor3_pwm,OUTPUT);
    
    pinMode(motor4_dir1,OUTPUT);
    pinMode(motor4_dir2,OUTPUT);
    pinMode(motor4_pwm,OUTPUT);
    
  
    digitalWrite(motor3_dir1,0);
    digitalWrite(motor3_dir2,1);
    digitalWrite(motor3_pwm,1);
  
    digitalWrite(motor4_dir1,0);
    digitalWrite(motor4_dir2,1);
    digitalWrite(motor4_pwm,1);
}
void loop()
{
   long duration,inches,cm;
    pinMode(trigPin,OUTPUT);
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    pinMode(echoPin,INPUT);
    duration=pulseIn(echoPin,HIGH);
    inches= microsecondsToInches(duration);
     cm= microsecondsToCentimeters(duration);
          Serial.print(inches);
     Serial.print("in ");
     Serial.print(cm);
     Serial.print("cm ");
     Serial.println();
     delay(100);
     if(cm>60)
     {
      
    analogWrite(motor3_pwm, 200);
    analogWrite(motor4_pwm, 200);
    delay(500);
     }
     else
     {
      analogWrite(motor3_pwm, 0);
    analogWrite(motor4_pwm, 0);
    delay(500);
     }
}
long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
