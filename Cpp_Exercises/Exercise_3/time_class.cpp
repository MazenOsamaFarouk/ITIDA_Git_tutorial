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

    void AddTime(c_time time_1, c_time time_2)
    {
        int temp_total_seconds = time_1.m_total_seconds + time_2.m_total_seconds;

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

    void Display(void) const
    {
        if (m_days)
        {
            std::cout << std::endl
                      << m_days << " Days." << std::endl;
            std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << std::endl
                      << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl
                      << std::endl;
        }
    }
};

int main(void)
{
    const c_time time_1(600, 300, 200);
    const c_time time_2(400, 700, 800);
    c_time time_sum;

    time_1.Display();
    std::cout << "   +" << std::endl;
    time_2.Display();
    time_sum.AddTime(time_1, time_2);
    std::cout << "   =" << std::endl;
    time_sum.Display();

    return 0;
}