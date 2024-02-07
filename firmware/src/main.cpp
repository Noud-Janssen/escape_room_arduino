#include <Arduino.h>
#include "RFIDReader.h"
#include "driver/led.h"
// #include "LED.h"

#define RST_PIN 9
#define SS_PIN 10
#define LED_PIN 13

RFIDReader rfidReader(SS_PIN, RST_PIN);
driver::led succes_led(2);

byte key = 0x9E;

// LED led(LED_PIN);

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        ;
    rfidReader.begin();
    Serial.write("Init done");
}

void loop()
{
    if (!rfidReader.loop())
    {
        succes_led.off();
        return;
    }

    if (rfidReader.get_id(0) == key)
    {
        Serial.println(millis());
        Serial.println("test");
        succes_led.on();
    }
}