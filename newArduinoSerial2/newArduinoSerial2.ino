#include<Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;

int input;
int number=0;
int i=1;
int count=0;
int base0;
int sa0;
int base1;
int sa1;
int base2;
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  
  myservo1.attach(7);
  myservo2.attach(8);
  myservo3.attach(9);
  myservo4.attach(10);
  myservo5.attach(11);
  myservo6.attach(12);
  myservo7.attach(13);
  
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()>0)
  {
    input=(Serial.read()-'0');
    if(input!= -1)
    {
      if(input!=-16)
      {
       input=input*i; 
       number=number+input;
       i=i*10;
       
      } 
     else if(input==-16 && count==0)
     {
       base0=number;
       number=0;
       i=1;
       count=1;
     }
     else if(input==-16 && count==1)
     {
       sa0=number;
       i=1;
       number=0;
       count=2;
     }
     else if(input==-16 && count==2)
     {
       base1=number;
       number=0;
       i=1;
       count=3;
     }
     else if(input==-16 && count==3)
     {
       sa1=number;
       number=0;
       i=1;
       count=4;
      }
     else
     {
       base2=number;
       number=0;
       i=1;
     }
      
   }
   if(input== -1)
   { 
     int otherAngleSa0=140;
     int otherAngleSa1=140;
     Serial.print("base0 :");
     Serial.println(base0);
     Serial.print("sa0 :");
     Serial.println(sa0);
     Serial.print("base1:");
     Serial.println(base1);
     Serial.print("sa1 :");
     Serial.println(sa1);
     Serial.print("base2 :");
     Serial.println(base2);
     otherAngleSa0=140-sa0;
     otherAngleSa1=140-sa1;
     Serial.print("OtherAngleSa0 :");
     Serial.println(otherAngleSa0);
     Serial.print("OtherAngleSa1 :");
     Serial.println(otherAngleSa1);
     myservo1.write(base0);
     myservo2.write(sa0);
     myservo3.write(otherAngleSa0);
     myservo4.write(base1);
     myservo5.write(sa1);
     myservo6.write(otherAngleSa1);
     myservo7.write(base2);
     
     number=0;
     count=0;
   }  
        
 }
  
}
