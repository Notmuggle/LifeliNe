
int motor1_dir1 = 5;
int motor1_dir2 = 4;

int motor2_dir1 = 3;
int motor2_dir2 = 2;

const int trigPin1=11;
const int echoPin1=10;

const int trigPin2=8;
const int echoPin2=7;


void setup() {
   Serial.begin(9600);

    pinMode(motor1_dir1,OUTPUT);
    pinMode(motor1_dir2,OUTPUT);
    
    pinMode(motor2_dir1,OUTPUT);
    pinMode(motor2_dir2,OUTPUT);
  
    digitalWrite(motor1_dir1,LOW);
    digitalWrite(motor1_dir2,LOW);
  
    digitalWrite(motor2_dir1,LOW);
    digitalWrite(motor2_dir2,LOW);
    
}

void loop() {

  long cm1,fadeaway,duration1,duration2,cm2,fadeaway1,fadeaway2;
   pinMode(trigPin1,OUTPUT);
    digitalWrite(trigPin1,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1,LOW);
    pinMode(echoPin1,INPUT);
    duration1=pulseIn(echoPin1,HIGH);
   cm1= microsecondsToCentimeters(duration1);
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
     cm2= microsecondsToCentimeters(duration2);
     Serial.print(cm2);
     Serial.print("cm2 ");
     Serial.println();
     delay(100);

      fadeaway=cm1*2.125;

 if(cm1<20)
  {
    if(cm2>20)
    {
      fadeaway2=(fadeaway/4);
    analogWrite( motor1_dir1, fadeaway2);                       
    analogWrite( motor1_dir2, 0);                           
    analogWrite( motor2_dir1, fadeaway);      //right
    analogWrite( motor2_dir2, 0);
    delay(100);
  }
  else
  {
  //motor_stop();
   analogWrite( motor1_dir1, 0);                       
    analogWrite( motor1_dir2, 0);                           
    analogWrite( motor2_dir1, 0);      
    analogWrite( motor2_dir2, 0);
    delay(100);
}
  }     
                                          
     else if(cm2<20)
{
  if(cm1>20)
  {
 // drive_left();
 fadeaway1=(fadeaway/4);
 analogWrite( motor1_dir1, fadeaway);                       
    analogWrite( motor1_dir2, 0);                           
    analogWrite( motor2_dir1, fadeaway1);      
    analogWrite( motor2_dir2, 0);
    delay(100);
}
else
  {
 // motor_stop();
 analogWrite( motor1_dir1, 0);                       
    analogWrite( motor1_dir2, 0);                           
    analogWrite( motor2_dir1, 0);      
    analogWrite( motor2_dir2, 0);
    delay(100);
}
}

 else
{
  //drive_forward();
 analogWrite( motor1_dir1, fadeaway);                       
    analogWrite( motor1_dir2, 0);                           
    analogWrite( motor2_dir1, fadeaway);     
    analogWrite( motor2_dir2, 0);
    delay(100);
 }

 
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
} 


