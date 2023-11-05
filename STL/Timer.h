#pragma once

#include <iostream>
#include <functional>
#include <chrono>

#define MILLI(t) (t*1000.0f)
#define MICRO(t) (MILLI(t)*1000.0f)
#define NANO(t)  (MICRO(t)*1000.0f)

#define TIME(fn, unit) \
{\
    Timer timer ;\
    fn ;\
    std::cout << #fn << " took " \
        << static_cast<float>(unit(timer.duration()))\
        << " "#unit << " seconds\n";\
}


class Timer
{
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::high_resolution_clock hrc;
public:
    Timer():isCalled(false)
    {
        m_start = hrc::now();
    }
    float duration()
    {
        isCalled = true;
        m_end  = hrc::now();
        m_exec_t = (m_end - m_start);
        return m_exec_t.count();
    }

    ~Timer()
    {
        if(!isCalled)
        {
            m_end  = hrc::now();
            m_exec_t = (m_end - m_start);
            std::cout << "Time: " << m_exec_t.count() << " ms\n" ;
        }
    }

private:
    bool isCalled ;
    hrc::time_point m_start, m_end;
    std::chrono::duration<float> m_exec_t ;
};