win32 {
    HOMEDIR += $$(USERPROFILE)
}
else {
    HOMEDIR += $$(HOME)
}

INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/cores/arduino"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/variants/eightanaloginputs"
INCLUDEPATH += "$${HOMEDIR}/.platformio/lib/DS3232RTC_ID78/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/lib/Time_ID44"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/__cores__/arduino/EEPROM/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/__cores__/arduino/HID/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/__cores__/arduino/SPI/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/__cores__/arduino/SoftwareSerial/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/__cores__/arduino/Wire/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Adafruit_Circuit_Playground"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Adafruit_Circuit_Playground/utility"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Bridge/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Esplora/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Ethernet/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Firmata"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Firmata/utility"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/GSM/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Keyboard/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/LiquidCrystal/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Mouse/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/RobotIRremote/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Robot_Control/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Robot_Motor/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/SD/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Servo/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/SpacebrewYun/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Stepper/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/TFT/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/Temboo/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/framework-arduinoavr/libraries/WiFi/src"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/toolchain-atmelavr/avr/include"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/toolchain-atmelavr/lib/gcc/avr/5.4.0/include"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/toolchain-atmelavr/lib/gcc/avr/5.4.0/include-fixed"
INCLUDEPATH += "$${HOMEDIR}/.platformio/packages/tool-unity"
INCLUDEPATH += "$${HOMEDIR}/src/qtcreator_projects/fishtank-controller/include"
INCLUDEPATH += "$${HOMEDIR}/src/qtcreator_projects/fishtank-controller/src"

DEFINES += "PLATFORMIO=30604"
DEFINES += "ARDUINO_AVR_NANO"
DEFINES += "F_CPU=16000000L"
DEFINES += "ARDUINO_ARCH_AVR"
DEFINES += "ARDUINO=10805"
DEFINES += "__AVR_ATmega328P__"

OTHER_FILES += platformio.ini

SOURCES += \
    src/main.cpp

HEADERS += \
    src/main.h

