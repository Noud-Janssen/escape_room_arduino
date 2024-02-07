#ifndef ESCAPE_DRIVER_RFID_H
#define ESCAPE_DRIVER_RFID_H

namespace driver
{
    class rfid
    {
    public:
        rfid();
        ~rfid() = default;
    public:
        void read();
        
    };    
} // namespace driver


#endif // ESCAPE_DRIVER_RFID_H