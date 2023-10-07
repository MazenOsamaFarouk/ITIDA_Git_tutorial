#include <iostream>

#define S32_MAX_VALUE 2147483647
#define SECONDS_IN_A_DAY 86400
#define Seconds_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

class c_time
{
private:
    int m_days;
    int m_hours;
    int m_minutes;
    int m_seconds;
    int m_total_seconds;

public:
    c_time() : m_days(0),
               m_hours(0),
               m_minutes(0),
               m_seconds(0),
               m_total_seconds(0)
    {
        /*do nothing*/
    }

    c_time(int hours, int minutes, int seconds)
    {
        int temp_total_seconds = (hours * Seconds_IN_HOUR) + (minutes * SECONDS_IN_MINUTE) + (seconds);
        FormatAndSave(temp_total_seconds);
    }

    void FormatAndSave(int temp_total_seconds)
    {
        if (temp_total_seconds < S32_MAX_VALUE && temp_total_seconds > 0)
        {
            m_total_seconds = temp_total_seconds;
            m_days = temp_total_seconds / SECONDS_IN_A_DAY;
            temp_total_seconds = temp_total_seconds % SECONDS_IN_A_DAY;
            m_hours = temp_total_seconds / Seconds_IN_HOUR;
            temp_total_seconds = temp_total_seconds % Seconds_IN_HOUR;
            m_minutes = temp_total_seconds / SECONDS_IN_MINUTE;
            temp_total_seconds = temp_total_seconds % SECONDS_IN_MINUTE;
            m_seconds = temp_total_seconds;
        }
        else
        {
            /*wrong user input will overwrite everything to 0*/
            m_days = 0;
            m_hours = 0;
            m_minutes = 0;
            m_seconds = 0;
            m_total_seconds = 0;
        }
    }

    c_time FormatAndSave_Operator(int temp_total_seconds) const
    {
        c_time temp_time;
        if (temp_total_seconds < S32_MAX_VALUE && temp_total_seconds > 0)
        {
            temp_time.m_total_seconds = temp_total_seconds;
            temp_time.m_days = temp_total_seconds / SECONDS_IN_A_DAY;
            temp_total_seconds = temp_total_seconds % SECONDS_IN_A_DAY;
            temp_time.m_hours = temp_total_seconds / Seconds_IN_HOUR;
            temp_total_seconds = temp_total_seconds % Seconds_IN_HOUR;
            temp_time.m_minutes = temp_total_seconds / SECONDS_IN_MINUTE;
            temp_total_seconds = temp_total_seconds % SECONDS_IN_MINUTE;
            temp_time.m_seconds = temp_total_seconds;
        }
        else
        {
            /*wrong user input will overwrite everything to 0*/
            temp_time.m_days = 0;
            temp_time.m_hours = 0;
            temp_time.m_minutes = 0;
            temp_time.m_seconds = 0;
            temp_time.m_total_seconds = 0;
        }
        return temp_time;
    }

    c_time operator+(const c_time time) const
    {
        int temp_total_seconds = m_total_seconds + time.m_total_seconds;
        return FormatAndSave_Operator(temp_total_seconds);
    }

    c_time operator-(const c_time time) const
    {
        int temp_total_seconds = m_total_seconds - time.m_total_seconds;
        return FormatAndSave_Operator(temp_total_seconds);
    }

    void Display(void) const
    {
        if (m_days)
        {
            std::cout << m_days << " Days." << std::endl;
            std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl;
        }
        else
        {
            std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl;
        }
    }
};

int main(void)
{
    const c_time time_1(600, 300, 200);
    const c_time time_2(400, 700, 800);
    c_time time_subtract;
    c_time time_sum;

    std::cout << std::endl;
    time_1.Display();
    std::cout << "   +" << std::endl;
    time_2.Display();
    time_sum = time_1 + time_2;
    std::cout << "   =" << std::endl;
    time_sum.Display();
    std::cout << std::endl;
    std::cout << "--------" << std::endl;
    std::cout << std::endl;
    time_1.Display();
    std::cout << "   -" << std::endl;
    time_2.Display();
    time_subtract = time_1 - time_2;
    std::cout << "   =" << std::endl;
    time_subtract.Display();
    std::cout << std::endl;

    return 0;
}