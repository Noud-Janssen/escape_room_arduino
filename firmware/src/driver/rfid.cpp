#include "driver/rfid.h"
#include <SPI.h>

namespace driver
{
    rfid::rfid()
        : mfrc522(9, 10)
    {
    }

    void rfid::init()
    {
        SPI.begin();        // Init SPI bus
        mfrc522.PCD_Init(); // Init MFRC522
    }

    bool rfid::read()
    {
        if (!mfrc522.PICC_IsNewCardPresent())
        {
            return false;
        }

        if (!mfrc522.PICC_ReadCardSerial())
        {
            return false;
        }

        return true;
    }

    byte rfid::get_id(byte index)
    {
        MFRC522::Uid *uid = &mfrc522.uid;

        for (byte i = 0; i < uid->size; i++)
        {
            if (i == index)
            {
                return uid->uidByte[i];
            }
        }
        return 0;
    }
} // namespace driver
