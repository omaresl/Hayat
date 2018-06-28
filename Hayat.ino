#include "Arduino.h"
#include "LiquidCrystal.h"
#include "SoftwareSerial.h"
#include "Arduino_FreeRTOS.h"
#include "OS/OS_PeriodicTasks.h"

//The setup function is called once at startup of the sketch
void setup()
{
	// Add your initialization code here

	ESP8266.begin(9600);
	lcd.begin(16, 2);
	pinMode(MP3, OUTPUT);
	pinMode(led, OUTPUT);
	pinMode(motor, OUTPUT);

	lcd.setCursor(0, 0); // Top left
	ESP8266.println("SHOWER CONTROL");
	lcd.print(" SHOWER CONTROL");
	lcd.setCursor(4, 1); // bottom left
	lcd.print("PROJECT");
	delay(2000);
	lcd.clear();

	//Create Task for the FreeRTOS
	xTaskCreate(
			OS_PeriodicTasks_100ms
			,  (const portCHAR *)"100ms"   // A name just for humans
			,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
			,  NULL
			,  0  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
			,  NULL );
}

// The loop function is called in an endless loop
void loop()
{
	//Add your repeated code here
}
