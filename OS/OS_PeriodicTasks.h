/*
 * OS_PeriodicTasks.h
 *
 *  Created on: 27/06/2018
 *      Author: Omar Sevilla
 */

#ifndef OS_PERIODICTASKS_H_
#define OS_PERIODICTASKS_H_
#include "Arduino.h"
#include "LiquidCrystal.h"
#include "SoftwareSerial.h"

extern LiquidCrystal lcd;

extern SoftwareSerial ESP8266;

extern const int analogInPin;  // Analog input pin that the potentiometer is attached to

extern int sensorValue;        // value read from the pot

#define MP3  	7 // the number of the buzzer pin
#define led  	6 // the number of the buzzer pin
#define motor	5 // the number of the buzzer pin

/* Function Declarations */
extern void OS_PeriodicTasks_100ms(void);


#endif /* OS_PERIODICTASKS_H_ */
