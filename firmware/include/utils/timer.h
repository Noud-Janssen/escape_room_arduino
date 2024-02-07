#ifndef ESCAPE_UTILS_TIMER_H
#define ESCAPE_UTILS_TIMER_H

#include <Arduino.h>

namespace utils
{
    class timer
    {
    public:
        timer(uint32_t milliseconds);
        ~timer() = default;
    public:
        void start(uint32_t milliseconds = 0);
        bool is_triggered();
    private:
        uint32_t m_start_time;
        uint32_t m_hit_time;
        bool m_running;
    };
} // namespace utils



#endif // ESCAPE_UTILS_TIMER_H