#include <LiquidCrystal.h> 

                                       
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   


const int trigPin = 11; 
const int echoPin = 10;  
const int motorpin = 9;
const int sensorIR = 8;
const int LEDoff = 13;
const int LEDon = 12;

long duration;                
int distanceCm;

void setup() 
{     
  lcd.begin(16,2);                                                   
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

pinMode(9,OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);


  digitalWrite(12, LOW); 
  digitalWrite(13, HIGH); 

  delay(100);

  welcome();

}

void loop() 
{   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;

     if (distanceCm <= 100)
    {
     adaorang();
    }
     else
    { 
     digitalWrite(12, LOW); 
     digitalWrite(13, HIGH); 
     analogWrite(9,0); 
     delay(20);
     
     welcome();
    }


}
void adaorang()
{
  lcd.setCursor(0,0);                                                 
  lcd.print("ELEKTRO ITK ");
  lcd.setCursor(0,1);
  lcd.print("ACDC CHAMBER ");
  delay(100);
  lcd.clear();
   
    if(digitalRead (sensorIR) == HIGH) 
   {
    analogWrite(9,255); 
    digitalWrite(12, HIGH); 
    digitalWrite(13, LOW); 
    delay(1000); 

    thanks();
   digitalWrite(12, LOW); 
     digitalWrite(13, HIGH); 
     analogWrite(9,0); 
     delay(20);
     
     welcome();
   }
   else
   {
    adaorang();
   }

}

void welcome()
{
  lcd.setCursor(0,0);                                                 
  lcd.print("HI THERE THIS IS");
  lcd.setCursor(0,1);
  lcd.print(" ACDC CHAMBER ");
  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);                                                 
  lcd.print("   BILIK ACDC   ");  
  lcd.setCursor(0,1);
  lcd.print("   READY TO USE   ");
  delay(100);
}

void thanks ()
{
  lcd.setCursor(0,0);                                                 
  lcd.print("  THANKS THERE  ");
  lcd.setCursor(0,1);
  lcd.print(" AND STAY SAFE ");
  delay(100);
  lcd.clear();
}
