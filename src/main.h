#ifndef MAIN_H
#define MAIN_H

#include "Arduino.h"
#include <TimeLib.h>
#include <Wire.h>
#include <DS3232RTC.h>  // a basic DS3232RTC library that returns time as a time_t

void printDigits(int digits);
void digitalClockDisplay();
unsigned long processSyncMessage();

static const char * TIME_HEADER = "T";   // Header tag for serial time sync message

#endif // MAIN_H
