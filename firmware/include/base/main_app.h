#ifndef ESCAPE_BASE_MAIN_APP_H
#define ESCAPE_BASE_MAIN_APP_H

#include "utils/timer.h"
#include "driver/led.h"
// #include "MFRC522.h"

namespace base
{
    class main_app
    {
    public:
        main_app();
        ~main_app() = default;
    public:
        void init();
        void loop();
    private:
        driver::led m_led;
        utils::timer m_timer;
    };

    
} // namespace base


#endif // ESCAPE_BASE_MAIN_APP_H