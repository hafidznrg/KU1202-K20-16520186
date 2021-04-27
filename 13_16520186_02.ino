#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
const int pingPin = A1;
long duration, cm, digit;

void setup(){
	lcd.begin(16,2);
  	lcd.print("PING Sensor");
}

void loop()
{
  	cm = read_sensor_ultrasonic();
  	
	lcd.setCursor(0,1);
	lcd.print("Jarak ");
  	lcd.setCursor(6,1);
  	lcd.print(cm);
  	print_unit_cm(cm);
}

long read_sensor_ultrasonic(){
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);

    pinMode(pingPin, INPUT);
  	duration = pulseIn(pingPin, HIGH);
    cm = duration/29/2;
  	return cm;
}

void print_unit_cm(long cm){
	digit = 0;
 	while (cm > 9){
  		digit += 1;
    	cm = cm/10;
  	}
  	digit += 1;
  	lcd.setCursor(6+digit,1);
  	lcd.print("cm");
  	for (int i=7+digit; i<16; i++){
    	lcd.print(" ");
  	}
}