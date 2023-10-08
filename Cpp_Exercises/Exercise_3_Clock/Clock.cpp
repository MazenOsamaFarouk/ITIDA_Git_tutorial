#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

#define SECONDS_IN_A_DAY 86400
#define SECONDS_IN_HALF_DAY 43200
#define Seconds_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

void CursorPositionWindows(short int x, short int y);

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

    c_time operator++(int)
    {
        m_TimeInSeconds++;
        Set_Time_Seconds(m_TimeInSeconds);
        return (*this);
    }

    c_time operator++(void)
    {
        ++m_TimeInSeconds;
        FormatAndSave(m_TimeInSeconds);
        return (*this);
    }

    bool Reset_Check(void) const
    {
        return reset;
    }

    void Reset_Time(void)
    {
        Set_Time_Seconds(0);
    }

    void DisplayHelpList(void) const
    {
        std::cout << std::endl
                  << "  Welcome to Clock Program v0.0.1." << std::endl;
        std::cout << "|---------------Help---------------|" << std::endl;
        std::cout << "|Press \"s\" To Set Time.            |" << std::endl;
        std::cout << "|Input \"a\"for 12 hour format.      |" << std::endl;
        std::cout << "|Input \"t\"for 24 hour format.      |" << std::endl;
        std::cout << "|Press \"ctrl+c\" to exit.           |" << std::endl;
        std::cout << "*---------------End.---------------*" << std::endl
                  << std::endl;
    }

    void print(void) const
    {
        std::cout << std::setw(2) << std::setfill('0') << m_hours;
        std::cout << ":";
        std::cout << std::setw(2) << std::setfill('0') << m_minutes;
        std::cout << ":";
        std::cout << std::setw(2) << std::setfill('0') << m_seconds;
    }

    void print_am_pm(void) const
    {
        int temp_hours = 0;
        if (m_TimeInSeconds >= SECONDS_IN_HALF_DAY)
        {
            if (m_hours > 12)
            {
                temp_hours = m_hours - 12;
                std::cout << std::setw(2) << std::setfill('0') << temp_hours;
                std::cout << ":";
                std::cout << std::setw(2) << std::setfill('0') << m_minutes;
                std::cout << ":";
                std::cout << std::setw(2) << std::setfill('0') << m_seconds;
                std::cout << " PM";
            }
            else
            {
                std::cout << std::setw(2) << std::setfill('0') << m_hours;
                std::cout << ":";
                std::cout << std::setw(2) << std::setfill('0') << m_minutes;
                std::cout << ":";
                std::cout << std::setw(2) << std::setfill('0') << m_seconds;
                std::cout << " PM";
            }
        }
        else
        {
            if (m_hours == 0)
            {
                temp_hours = 12;
                std::cout << std::setw(2) << std::setfill('0') << temp_hours;
                std::cout << ":";
                std::cout << std::setw(2) << std::setfill('0') << m_minutes;
                std::cout << ":";
                std::cout << std::setw(2) << std::setfill('0') << m_seconds;
                std::cout << " AM";
            }
            else
            {
                std::cout << std::setw(2) << std::setfill('0') << m_hours;
                std::cout << ":";
                std::cout << std::setw(2) << std::setfill('0') << m_minutes;
                std::cout << ":";
                std::cout << std::setw(2) << std::setfill('0') << m_seconds;
                std::cout << " AM";
            }
        }
    }
};

int main(void)
{
    char user_input = 0, buffer = 0;
    std::string string_input;
    short int hour = 0, minute = 0;
    c_time Clock;

    while (user_input != 'e')
    {
        system("cls");
        Clock.DisplayHelpList();

        std::cout << "User Input: ";
        std::cin >> user_input;
        std::tolower(user_input);

        switch (user_input)
        {
        case 's':
            system("cls");
            std::cout << "Please Input Time in this format \"hh:mm\"." << std::endl;
            std::cin >> hour >> buffer >> minute;
            std::cout << "am or pm Please use Lower case" << std::endl;
            std::cin >> string_input;
            if (string_input == "pm" && hour != 12)
            {
                hour += 12;
            }
            if (string_input == "am" && hour == 12)
            {
                hour -= 12;
            }
            Clock.Set_Time(hour, minute, 0);
            break;
        case 'a':
            system("cls");
            while (1)
            {
                CursorPositionWindows(0, 0);
                Clock.print_am_pm();
                Clock++;
                Sleep(1000);
            }
            break;
        case 't':
            system("cls");
            while (1)
            {
                CursorPositionWindows(0, 0);
                Clock.print();
                Clock++;
                Sleep(1000);
            }
            break;
        }
    };

    return 0;
}

void CursorPositionWindows(short int x, short int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};

    SetConsoleCursorPosition(hStdout, position);
}