#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#include "RFIDReader.h"
#include "driver/led.h"
#include "utils/timer.h"

enum card_types
{
    C1 = 30,
    C2 = 158,
    C3 = 206,
    C4 = 77,
    C5 = 221,
    C6 = 29,
    PHONE_NOET = 8
};

RFIDReader rfidReader(10, 19);
driver::led succes_led(2);
LiquidCrystal lcd(8, 3, 4, 5, 6, 7);

int time = 60;
bool card = false;
bool new_card;
bool on = false;

// LED led(LED_PIN);
void draw();

int id = -1;
int previous_id = 0;

String output;

byte square_char[8] = {
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b01110,
};

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        ;
    rfidReader.begin();
    Serial.println("Init done");
    lcd.begin(16, 2);
    lcd.createChar(0, square_char);
}

void loop()
{
    time = 60 - millis() / 1000;

    card = rfidReader.read();
    if (card)
    {
        previous_id = id;
        id = rfidReader.get_id(0);
        if (id == C1 && !on)
        {
            on = true;
        }
    }
    draw();
}

void draw()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    switch (id)
    {
    case C1:
        lcd.print("On");
        break;
    case C2:
        lcd.print("Krypton");
        break;
    case C3:
        lcd.print("Barium");
        break;
    case C4:
        lcd.print("Copper");
        break;
    case C5:
        lcd.print("Carbon");
        break;
    case C6:
        lcd.print("Hydrogen");
        break;
    case PHONE_NOET:
        lcd.print("Telefoon noet");
        break;
    default:
        lcd.print("ERROR [");
        lcd.print(id);
        lcd.print("]");
        lcd.setCursor(0, 1);
        lcd.print("ID not found");
        break;
    }
    lcd.setCursor(0, 1);
}