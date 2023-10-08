#include <iostream>

#define SECONDS_IN_A_DAY 86400
#define SECONDS_IN_HALF_DAY 43200
#define Seconds_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

class c_time
{
private:
    bool reset;
    int m_TimeInSeconds;
    unsigned short int m_hours;
    unsigned short int m_minutes;
    unsigned short int m_seconds;

    bool FormatAndSave(int Copy_TimeInSeconds)
    {
        if (Copy_TimeInSeconds > 0 && Copy_TimeInSeconds < SECONDS_IN_A_DAY)
        {
            m_TimeInSeconds = Copy_TimeInSeconds;
            m_hours = Copy_TimeInSeconds / Seconds_IN_HOUR;
            Copy_TimeInSeconds = Copy_TimeInSeconds % Seconds_IN_HOUR;
            m_minutes = Copy_TimeInSeconds / SECONDS_IN_MINUTE;
            Copy_TimeInSeconds = Copy_TimeInSeconds % SECONDS_IN_MINUTE;
            m_seconds = Copy_TimeInSeconds;
            reset = false;
        }
        else /*cases: 1-Got a wrong input resetting to 0:0:0. 2-While passing time reached 23:59:59,so next count will reset to 0:0:0*/
        {
            m_hours = 0;
            m_minutes = 0;
            m_seconds = 0;
            m_TimeInSeconds = 0;
            reset = true;
        }
        return reset;
    }

public:
    c_time() : reset(false),
               m_hours(0),
               m_minutes(0),
               m_seconds(0),
               m_TimeInSeconds(0)
    {
        /*do nothing*/
    }

    bool Set_Time_Seconds(int Copy_TimeInSeconds)
    {
        return FormatAndSave(Copy_TimeInSeconds);
    }

    bool Set_Time(int Copy_Hours, int Copy_Minutes, int Copy_Seconds)
    {
        return FormatAndSave(((Copy_Hours * Seconds_IN_HOUR) + (Copy_Minutes * SECONDS_IN_MINUTE) + (Copy_Seconds)));
    }

    c_time Add(c_time const &other_time) const
    {
        c_time Add_temp;
        Add_temp.Set_Time_Seconds((m_TimeInSeconds + other_time.m_TimeInSeconds));
        return Add_temp;
    }

    c_time Subtract(c_time const &other_time) const
    {
        c_time Subtract_temp;
        Subtract_temp.Set_Time_Seconds((m_TimeInSeconds - other_time.m_TimeInSeconds));
        return Subtract_temp;
    }

    bool Reset_Check(void) const
    {
        return reset;
    }

    void Reset_Time(void)
    {
        Set_Time_Seconds(0);
    }

    void print(void) const
    {
        std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl;
    }

    void print_am_pm(void) const
    {
        int temp_hours = 0;
        if (m_TimeInSeconds >= SECONDS_IN_HALF_DAY)
        {
            if (m_hours > 12)
            {
                temp_hours = m_hours - 12;
                std::cout << temp_hours << ":" << m_minutes << ":" << m_seconds << " PM" << std::endl;
            }
            else
            {
                std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << " PM" << std::endl;
            }
        }
        else
        {
            if (m_hours == 0)
            {
                temp_hours = 12;
                std::cout << temp_hours << ":" << m_minutes << ":" << m_seconds << " AM" << std::endl;
            }
            else
            {
                std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << " AM" << std::endl;
            }
        }
    }
};

int main(void)
{
    c_time time_1, time_2, time_3, add_result, subtract_result;

    time_1.Set_Time(12, 30, 40);
    time_2.Set_Time(3, 4, 25);
    time_3.Set_Time_Seconds(3600);

    add_result = time_1.Add(time_2).Add(time_3);
    subtract_result = time_1.Subtract(time_2).Subtract(time_3);

    add_result.print();
    subtract_result.print();
    add_result.print_am_pm();
    subtract_result.print_am_pm();
    return 0;
}