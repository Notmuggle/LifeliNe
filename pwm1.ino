
int motor1_dir1 = 5;                 //for single ultrasonic sensor
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

  long cm1,fadeaway,duration1;
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
    fadeaway=cm1*2.125;                                         //converting the range which was max read by our ultrasonic sensor is 120.. so keeping this as max, change the distance values in the range of 255(max of motor)
    analogWrite( motor1_dir1, fadeaway);                         //just like % ratio in 100 here we take in the range of 255.. there fore..(X*255)/120 = X*2.125.. which is taken as constant here..should be changed acc to 
    analogWrite( motor1_dir2, 0);                           // the surroundings included.
    analogWrite( motor2_dir1, fadeaway);
    analogWrite( motor2_dir2, 0);
    delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
} 


