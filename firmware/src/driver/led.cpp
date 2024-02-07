#include "driver/led.h"

namespace driver
{
    led::led(uint8_t pin)
        : m_pin(pin)
    {
    }

    void led::on()
    {
        digitalWrite(m_pin,1);
    }

    void led::off()
    {
        digitalWrite(m_pin,0);
    }

    void led::toggle()
    {
        digitalWrite(m_pin,!read());
    }

    bool led::read()
    {
        digitalRead(m_pin);
    }
} // namespace driver
