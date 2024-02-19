#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

class RFIDReader
{
public:
    RFIDReader(int ssPin, int rstPin) : mfrc522(ssPin, rstPin) {}

    void begin()
    {
        SPI.begin();
        mfrc522.PCD_Init();
    }

    bool read()
    {
        if (!mfrc522.PICC_IsNewCardPresent())
        {
            return false;
        }

        if (!mfrc522.PICC_ReadCardSerial())
        {
            return false;
        }

        MFRC522::Uid *uid = &mfrc522.uid;
        for (byte i = 0; i < uid->size; i++)
        {
            id[i] = uid->uidByte[i];
        }
        return true;
    }

    byte get_id(byte index)
    {
        return id[index];
    }

private:
    MFRC522 mfrc522;

    byte id[4];
};