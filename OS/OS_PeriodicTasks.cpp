/*
 * OS_PeriodicTasks.cpp
 *
 *  Created on: 27/06/2018
 *      Author: Omar Sevilla
 */
#include "OS_PeriodicTasks.h"

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

SoftwareSerial ESP8266(0, 1); // RX, TX

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot

/* **************************************************
 * Function Name: OS_PeriodicTasks_100ms
 * Description: TBD
 * Parameters: N/A
 * Return Value: N/A
 * **************************************************/
void OS_PeriodicTasks_100ms(void)
{
	if(millis()/1000<=360){
		digitalWrite(MP3, HIGH);
		digitalWrite(motor, HIGH);
	}
	lcd.setCursor(0, 0);

	// print the number of seconds since reset:
	lcd.print("Timer in SEC:");

	if(millis()/1000>0&&millis()/1000<360) {lcd.print(millis() / 1000);} //6min timer in sec disply

	if(millis()/1000>=240&&millis()/1000<=243){digitalWrite(led, HIGH);delay(500);}//led blinks fOr 3sec On 4th min
	else{digitalWrite(led, LOW);}
	if(millis()/1000>=300&&millis()/1000<=303){digitalWrite(led, HIGH);delay(500);}//led blinks fOr 3sec On 5th min
	else{digitalWrite(led, LOW);}
	if(millis()/1000>=360&&millis()){digitalWrite(led, HIGH);delay(500);}//led blinks fOr 3sec On 5th min

	if(millis()/1000>=240&&millis()/1000<=243) {digitalWrite(motor, LOW);}//3sec mtr speed cntrl  On 4min
	else{digitalWrite(motor, HIGH);}


	if(millis()/1000>=60&&millis()/1000<=120) {lcd.setCursor(0, 1);lcd.print("1min completed  ");}
	if(millis()/1000>120&&millis()/1000<=180){lcd.setCursor(0, 1);lcd.print("2min completed  ");}
	if(millis()/1000>180&&millis()/1000<=240){lcd.setCursor(0, 1);lcd.print("3min completed  ");}
	if(millis()/1000>240&&millis()/1000<=300){lcd.setCursor(0, 1);lcd.print("4min completed  ");} //4rd min led flashes
	if(millis()/1000>300&&millis()/1000<=360){lcd.setCursor(0, 1);lcd.print("5min completed  ");} //5rd min led flashes
	if(millis()/1000>=360){lcd.setCursor(0, 1);lcd.print("6min completed  ");digitalWrite(motor, HIGH);digitalWrite(MP3, LOW);digitalWrite(led, LOW);}//after 4 min led,motr,mp3 stop

	// put your main code here, to run repeatedly:
	sensorValue = analogRead(analogInPin);
	ESP8266.println(":Water flow:");
	ESP8266.println(sensorValue);
	ESP8266.println("ML");

}
