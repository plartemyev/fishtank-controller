/*
 * TimeRTC.pde
 * example code illustrating Time library with Real Time Clock.
 *
 */

#include "Arduino.h"
#include <TimeLib.h>
#include <Wire.h>
#include <DS3232RTC.h>  // a basic DS3232RTC library that returns time as a time_t

void printDigits(int digits);
void digitalClockDisplay();
unsigned long processSyncMessage();

static const char * TIME_HEADER = "T";   // Header tag for serial time sync message

void setup()  {
    Serial.begin(115200);
    while (!Serial); // wait until Arduino Serial Monitor opens
    setSyncProvider(RTC.get);   // the function to get the time from the RTC
    if(timeStatus()!= timeSet)
        Serial.println("Unable to sync with the RTC");
    else
        Serial.println("RTC has set the system time");
}

void loop()
{
    if (Serial.available()) {
        time_t t = processSyncMessage();
        if (t != 0) {
            RTC.set(t);   // set the RTC and the system time to the received value
            setTime(t);
        }
    }
    if (timeStatus() == timeSet) {
        digitalClockDisplay();
    } else {
        Serial.println("The time has not been set.  Please run the Time");
        Serial.println("TimeRTCSet example, or DS1307RTC SetTime example.");
        Serial.println();
        delay(4000);
    }
    delay(1000);
}

unsigned long processSyncMessage() {
    /*  code to process time sync messages from the serial port   */
    unsigned long pctime = 0L;
    const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

    if(Serial.find(*TIME_HEADER)) {
        pctime = static_cast<unsigned long>(Serial.parseInt());
        if( pctime < DEFAULT_TIME) { // check the value is a valid time (greater than Jan 1 2013)
            pctime = 0L; // return 0 to indicate that the time is not valid
        }
        return pctime;
    }
    return pctime;
}

void digitalClockDisplay(){
    // digital clock display of the time
    Serial.print(hour());
    printDigits(minute());
    printDigits(second());
    Serial.print(" ");
    Serial.print(day());
    Serial.print(" ");
    Serial.print(month());
    Serial.print(" ");
    Serial.print(year());
    Serial.println();
}

void printDigits(int digits){
    // utility function for digital clock display: prints preceding colon and leading 0
    Serial.print(":");
    if(digits < 10)
        Serial.print('0');
    Serial.print(digits);
}
