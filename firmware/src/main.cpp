#include <Arduino.h>

// #include "base/main_app.h"
// #include "MFRC522.h"

// base::main_app app;
// MFRC522 m_reader(10, 5);

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9 // Configurable, see typical pin layout above
#define SS_PIN 10 // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup()
{
  Serial.begin(9600); // Initialize serial communications with the PC
  while (!Serial)
    ;                 // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();        // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522
  delay(4);           // Optional delay. Some board do need more time after init to be ready, see Readme
  // mfrc522.PICC_DumpToSerial();	// Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop()
{
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  MFRC522::Uid *uid = &mfrc522.uid;


  // UID
	Serial.print("Card UID:");
	for (byte i = 0; i < uid->size; i++) {
		Serial.print(uid->uidByte[i] < 0x10 ? " 0" : " ");
		Serial.print(uid->uidByte[i], HEX);
	} 
  Serial.println();
}