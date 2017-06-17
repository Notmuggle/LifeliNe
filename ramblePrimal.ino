int motor1_dir1 = 5;
int motor1_dir2 = 4;
//int motor1_pwm  = 9;

int motor2_dir1 = 3;
int motor2_dir2 = 2;
//int motor2_pwm  = 6;

const int trigPin1=9;
const int echoPin1=10;

const int trigPin2=8;
const int echoPin2=7;
void setup()
{
    Serial.begin(9600);

    pinMode(motor1_dir1,OUTPUT);
    pinMode(motor1_dir2,OUTPUT);
//    pinMode(motor1_pwm,OUTPUT);
    
    pinMode(motor2_dir1,OUTPUT);
    pinMode(motor2_dir2,OUTPUT);
   // pinMode(motor2_pwm,OUTPUT);
    
  
    digitalWrite(motor1_dir1,LOW);
    digitalWrite(motor1_dir2,HIGH);
//    digitalWrite(motor1_pwm,HIGH);
  
    digitalWrite(motor2_dir1,LOW);
    digitalWrite(motor2_dir2,HIGH);
  //  digitalWrite(motor2_pwm,HIGH);
}
void loop()
{
  long duration2,inches2,cm2,duration1,inches1,cm1;
    pinMode(trigPin1,OUTPUT);
    digitalWrite(trigPin1,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1,LOW);
    pinMode(echoPin1,INPUT);
    duration1=pulseIn(echoPin1,HIGH);
    inches1= microsecondsToInches(duration1);
     cm1= microsecondsToCentimeters(duration1);
     Serial.print(inches1);
     Serial.print("in1 ");
     Serial.print(cm1);
     Serial.print("cm1 ");
     Serial.println();
     delay(100);

      pinMode(trigPin2,OUTPUT);
    digitalWrite(trigPin2,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2,LOW);
    pinMode(echoPin2,INPUT);
    duration2=pulseIn(echoPin2,HIGH);
    inches2= microsecondsToInches(duration2);
     cm2= microsecondsToCentimeters(duration2);
     Serial.print(inches2);
     Serial.print("in2 ");
     Serial.print(cm2);
     Serial.print("cm2 ");
     Serial.println();
     delay(100);
     
  if(cm1<20)
  {
    if(cm2>20)
    {
    drive_right();
  }
  else
  {
  motor_stop();
}
  }
  else if(cm2<20)
{
  if(cm1>20)
  {
  drive_left();
}
else
  {
  motor_stop();
}
}
 else
{
  drive_forward();
 
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


void drive_forward()
{ 
digitalWrite(motor1_dir1, LOW); 
digitalWrite(motor1_dir2, HIGH); 
digitalWrite(motor2_dir1, LOW);
digitalWrite(motor2_dir2, HIGH);
delay(20);
return;
}
void motor_stop()
{
digitalWrite(motor1_dir1, LOW);
digitalWrite(motor1_dir2, LOW); 
digitalWrite(motor2_dir1, LOW);
digitalWrite(motor2_dir2, LOW);
delay(20);
return;
}
void drive_left()
{
 digitalWrite(motor1_dir1, LOW);
digitalWrite(motor1_dir2, HIGH); 
digitalWrite(motor2_dir1, LOW);
digitalWrite(motor2_dir2, LOW);
delay(20);
return; 
}

void drive_right()
{
 digitalWrite(motor1_dir1, LOW);
digitalWrite(motor1_dir2, LOW); 
digitalWrite(motor2_dir1, LOW);
digitalWrite(motor2_dir2, HIGH);
delay(20);
return; 
}

