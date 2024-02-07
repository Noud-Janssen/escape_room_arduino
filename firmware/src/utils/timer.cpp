#include "utils/timer.h"

namespace utils
{
    timer::timer(uint32_t milliseconds)
        : m_hit_time(milliseconds),
          m_running(false)
    {
    }

    void timer::start(uint32_t milliseconds)
    {
        if (milliseconds != 0)
        {
            m_hit_time = milliseconds;
        }
        m_running = true;
        m_start_time = millis();
    }

    bool timer::is_triggered()
    {
        if (millis() >= m_start_time + m_hit_time)
        {
            m_start_time = millis();
            return true;
        }
        return false;
    }
} // namespace utils
