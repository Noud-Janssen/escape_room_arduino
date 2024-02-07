#ifndef ESCAPE_DRIVER_RFID_H
#define ESCAPE_DRIVER_RFID_H

#include <Arduino.h>
#include <MFRC522.h>

namespace driver
{
    class rfid
    {
    public:
        rfid();
        ~rfid() = default;
    public:
        void init();
        bool read();
        byte get_id(byte index);
    private:
        MFRC522 mfrc522;
    };    
} // namespace driver


#endif // ESCAPE_DRIVER_RFID_H