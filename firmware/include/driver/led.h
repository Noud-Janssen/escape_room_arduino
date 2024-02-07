#ifndef ESCAPE_DRIVER_LED_H
#define ESCAPE_DRIVER_LED_H

#include <Arduino.h>

namespace driver
{
    class led
    {
    public:
        led(uint8_t pin);
        ~led() = default;
    public:
        /**
         * @brief Turn the LED on
         * 
         */
        void on();
        /**
         * @brief Turn the LED off
         * 
         */
        void off();
        /**
         * @brief Toggle the LED
         * 
         */
        void toggle();
        /**
         * @brief Reads the LED
         * 
         * @return true 
         * @return false 
         */
        bool read();
    private:
        uint8_t m_pin;
    };    
} // namespace driver


#endif // ESCAPE_DRIVER_LED_H