#include  <LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);//scl-A5    sda-A4

int buzzer = 10;
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

void setup()
{
   lcd.init();                      // initialize the lcd 
  lcd.init();
 
  lcd.backlight();

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
}
void loop()
{
  
 digitalWrite(LeftMotorForward, LOW);
 digitalWrite(RightMotorForward, LOW);
  
 digitalWrite(LeftMotorBackward, HIGH);
 digitalWrite(RightMotorBackward, HIGH); 
 
 
 lcd.setCursor(0,0);
 lcd.print("vehicle-motion");
 lcd.setCursor(0,1);
 lcd.print("for-30-sec");
 delay(25000);

 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("vehicle-gonna-stop");
 lcd.setCursor(0,1);
 lcd.print("after-05-sec");
 
 analogWrite(buzzer,30);
 delay(5000);
 analogWrite(buzzer,0);
 
 lcd.clear();
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  lcd.setCursor(0,0);
 lcd.print("vehicle-rest");
 lcd.setCursor(0,1);
 lcd.print("for-10-sec");

 delay(9000);
 analogWrite(buzzer,30);
 delay(1000);
 analogWrite(buzzer,0);
  
}
