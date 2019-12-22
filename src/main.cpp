#include "main.h"

#define DHTPIN 12
#define DHTTYPE DHT22
#define HEATER_PIN 13
#define VIBRO_PIN 11
#define HALFSTEP 8
#define motorPin1  7     // IN1 on the ULN2003 driver 1
#define motorPin2  8     // IN2 on the ULN2003 driver 1
#define motorPin3  9     // IN3 on the ULN2003 driver 1
#define motorPin4  10     // IN4 on the ULN2003 driver 1
#define FIRST_FEEDING_HOUR 8
#define FIRST_FEEDING_MINUTE 1
#define SECOND_FEEDING_HOUR 21
#define SECOND_FEEDING_MINUTE 55
DHT_Unified dht(DHTPIN, DHTTYPE);
// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the 28BYJ-48 AccelStepper with ULN2003 driver (4096 steps per circle)
AccelStepper feeder_stepper(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);


static const char * TIME_HEADER = "T";   // Header tag for serial time sync message
static unsigned delayMS;

void setup() {
    pinMode(HEATER_PIN, OUTPUT);
    digitalWrite(HEATER_PIN, LOW);
    pinMode(VIBRO_PIN, OUTPUT);
    digitalWrite(VIBRO_PIN, LOW);
    Serial.begin(115200);
    dht.begin();
    sensor_t sensor;
    dht.temperature().getSensor(&sensor);
    delayMS = sensor.min_delay / 1000;
    while (!Serial); // wait until Arduino Serial Monitor opens
    setSyncProvider(RTC.get);   // the function to get the time from the RTC
    if(timeStatus()!= timeSet)
        Serial.println("Unable to sync with the RTC");
    else
        Serial.println("RTC has set the system time!");
    feeder_stepper.setMaxSpeed(600.0);
    feeder_stepper.setAcceleration(100.0);
    feeder_stepper.setSpeed(200);
}

void loop()
{
      // Delay between measurements.
      delay(delayMS);
      // Get temperature event and print its value.
      sensors_event_t event;
      dht.temperature().getEvent(&event);
      if (isnan(event.temperature)) {
        Serial.println("Error reading temperature!");
      }
      else {
        Serial.print("Temperature: ");
        Serial.print(event.temperature);
        Serial.println("°C");
        if(event.temperature <= 25) {
            digitalWrite(HEATER_PIN, HIGH);
            Serial.println("Heater turned on.");
        }
        else if (event.temperature >= 26) {
            digitalWrite(HEATER_PIN, LOW);
            Serial.println("Heater turned off.");
        }
      }
      // Get humidity event and print its value.
      dht.humidity().getEvent(&event);
      if (isnan(event.relative_humidity)) {
        Serial.println("Error reading humidity!");
      }
      else {
        Serial.print("Humidity: ");
        Serial.print(event.relative_humidity);
        Serial.println("%");
      }
    if (Serial.available()) {
        time_t t = processSyncMessage();
        if (t != 0) {
            RTC.set(t);   // set the RTC and the system time to the received value
            setTime(t);
        }
    }
    if (timeStatus() == timeSet) {
        if (hour() == FIRST_FEEDING_HOUR and minute() == FIRST_FEEDING_MINUTE){
            feedFish(1);
        } else if (hour() == SECOND_FEEDING_HOUR and minute() == SECOND_FEEDING_MINUTE){
            feedFish(1);
        }
        digitalClockDisplay();
    } else {
        Serial.println("The time has not been set.  Please run the Time by sending T${timestamp}");
        Serial.println();
        delay(4000);
    }
    delay(5000);
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
    Serial.print(year());
    Serial.print("-");
    Serial.print(month());
    Serial.print("-");
    Serial.print(day());
    Serial.println();
}

void printDigits(int digits){
    // utility function for digital clock display: prints preceding colon and leading 0
    Serial.print(":");
    if(digits < 10)
        Serial.print('0');
    Serial.print(digits);
}

void vibrate(unsigned long duration_millis){
    unsigned long start_time = millis();
    while (millis() - start_time < duration_millis){
        digitalWrite(VIBRO_PIN, HIGH);
        delay(100);
        digitalWrite(VIBRO_PIN, LOW);
        delay(50);
    }
}

void feedFish(int servings){
    Serial.println("Feeding time!");
    for (int i = 0; i < servings; i++){
        rotateFeederToStockPile();
        vibrate(1000);
        rotateFeederToOpening();
        vibrate(1000);
        rotateFeederToStockPile();
    }
    delay(40000);
}

void rotateFeederToStockPile(){
    feeder_stepper.runToNewPosition(0);
}

void rotateFeederToOpening(){
    feeder_stepper.runToNewPosition(2250);
}
