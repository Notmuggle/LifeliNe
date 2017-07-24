int motor1_dir1 = 5;
int motor1_dir2 = 4;

int motor2_dir1 = 3;
int motor2_dir2 = 2;

const int trigPin1=11;
const int echoPin1=10;

const int trigPin2=8;
const int echoPin2=6;
void setup()
{
    Serial.begin(9600);

    pinMode(motor1_dir1,OUTPUT);
    pinMode(motor1_dir2,OUTPUT);
    
    pinMode(motor2_dir1,OUTPUT);
    pinMode(motor2_dir2,OUTPUT);
    
  
    digitalWrite(motor1_dir1,LOW);
    digitalWrite(motor1_dir2,HIGH);
  
    digitalWrite(motor2_dir1,LOW);
    digitalWrite(motor2_dir2,HIGH);
}
void loop()
{
  long duration2,cm2,duration1,cm1;
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
     delay(200);

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
     delay(200);

if ((cm1<5))
    {
      analogWrite(motor1_dir1,0);
analogWrite(motor1_dir2, 0); 
analogWrite(motor2_dir1, 0);
analogWrite(motor2_dir2, 0);
delay(20);
      }
      else if((5 <= cm1 <15))
      {
       analogWrite(motor1_dir1,50);
analogWrite(motor1_dir2, 0); 
analogWrite(motor2_dir1, 0);
analogWrite(motor2_dir2, 0);
delay(20);
        }
        else if((15 <= cm1 <25))
        {
          analogWrite(motor1_dir1, 100);
          analogWrite(motor2_dir1, 100);
          }
          else if((25 <= cm1 < 45))
          {
            analogWrite(motor1_dir1, 150);
            analogWrite(motor2_dir1, 150);
            }
            else if((45 <= cm1 < 60))
            {
              analogWrite(motor1_dir1, 200);
              analogWrite(motor2_dir1, 200);
              }
              else if((60 <= cm1))
              {
                analogWrite(motor1_dir1, 255);
                analogWrite(motor2_dir1, 255);
                }
        
}
     long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}

