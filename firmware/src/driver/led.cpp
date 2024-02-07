#include "driver/led.h"

namespace driver
{
    led::led(uint8_t pin)
        : m_pin(pin)
    {
        pinMode(pin, OUTPUT); // sets the digital pin 13 as output
    }

    void led::on()
    {
        digitalWrite(m_pin, HIGH);
    }

    void led::off()
    {
        digitalWrite(m_pin, LOW);
    }

    void led::toggle()
    {
        digitalWrite(m_pin, !read());
    }

    bool led::read()
    {
        return digitalRead(m_pin);
    }
} // namespace driver
