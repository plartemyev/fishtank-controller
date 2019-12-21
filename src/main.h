#ifndef MAIN_H
#define MAIN_H

#include "Arduino.h"
#include <TimeLib.h>
#include <Wire.h>
#include <DS3232RTC.h>  // a basic DS3232RTC library that returns time as a time_t
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <AccelStepper.h>

void printDigits(int digits);
void digitalClockDisplay();
void rotateFeederToStockPile();
void rotateFeederToOpening();
void vibrate(unsigned long duration_millis);
void feedFish(int servings);
unsigned long processSyncMessage();
extern DHT_Unified dht;
extern AccelStepper feeder_stepper;

#endif // MAIN_H
