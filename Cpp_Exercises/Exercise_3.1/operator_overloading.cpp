#include <iostream>

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

    void FormatAndSave(int temp_total_seconds)
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

public:
    c_time() : m_days(0),
               m_hours(0),
               m_minutes(0),
               m_seconds(0),
               m_total_seconds(0)
    {
        /*do nothing*/
    }

    c_time(int temp_total_seconds)
    {
        FormatAndSave(temp_total_seconds);
    }

    c_time(int hours, int minutes, int seconds)
    {
        int temp_total_seconds = (hours * Seconds_IN_HOUR) + (minutes * SECONDS_IN_MINUTE) + (seconds);
        FormatAndSave(temp_total_seconds);
    }

    c_time Add(const c_time &other_time) const
    {
        return c_time(m_total_seconds + other_time.m_total_seconds);
    }

    c_time Subtract(const c_time &other_time) const
    {
        return c_time(m_total_seconds - other_time.m_total_seconds);
    }

    c_time operator+(const c_time &other_time) const
    {
        return Add(other_time);
    }

    c_time operator-(const c_time &other_time) const
    {
        return Subtract(other_time);
    }

    void print(void) const
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
    const c_time time_3(86400);
    c_time time_subtract;
    c_time time_sum;

    // time_sum = time_1.Add(time_2).Add(time_3);
    // time_subtract = time_1.Subtract(time_2).Subtract(time_3);
    time_sum = time_1 + time_2 + time_3;
    time_subtract = time_1 - time_2 - time_3;

    time_sum.print();
    time_subtract.print();

    return 0;
}