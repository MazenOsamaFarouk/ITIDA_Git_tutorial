#include <iostream>
#include <iomanip>
#include <windows.h>
#include <thread>
#include <mutex>

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

    c_time operator++(int)
    {
        m_TimeInSeconds++;
        FormatAndSave(m_TimeInSeconds);
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
        std::cout << "|Input \"a\" Display Clock AM/PM.    |" << std::endl;
        std::cout << "|Input \"t\" Display Clock 24 hour.  |" << std::endl;
        std::cout << "|Input \"r\" To reset Clock.         |" << std::endl;
        std::cout << "|Press \"e\" to exit.                |" << std::endl;
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

std::mutex mtx;
void Thread_1_ReadUserInput(void);
void Thread_2_DisplayClock(void);

void CursorPositionWindows(short int x, short int y);
void ShowConsoleCursor(bool showFlag);

int Get_Time(void);

char user_input(0);
c_time Clock;

int main(void)
{
    ShowConsoleCursor(false);
    system("cls");

    std::thread Input(Thread_1_ReadUserInput);
    std::thread Display(Thread_2_DisplayClock);

    Input.join();
    Display.join();

    system("cls");
    std::cout << "Bye." << std::endl;

    return 0;
}

void Thread_1_ReadUserInput(void)
{
    while (user_input != 'e')
    {
        bool reset = false;

        mtx.lock();
        system("cls");
        CursorPositionWindows(0, 1);
        Clock.DisplayHelpList();
        std::cout << "User Input: ";
        mtx.unlock();

        std::cin >> user_input;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::tolower(user_input);
        }

        switch (user_input)
        {
        case 's':
            mtx.lock();
            do
            {
                reset = Clock.Set_Time_Seconds(Get_Time());
            } while (reset);
            mtx.unlock();
            break;
        case 'r':
            Clock.Reset_Time();
            break;
        };
        Sleep(150);
    }
}

void Thread_2_DisplayClock(void)
{
    while (user_input != 'e')
    {
        mtx.lock();
        if (user_input == 'a')
        {
            CursorPositionWindows(12, 0);
            Clock.print_am_pm();
            CursorPositionWindows(12, 11);
        }
        else if (user_input == 't')
        {
            CursorPositionWindows(12, 0);
            Clock.print();
            CursorPositionWindows(12, 11);
        }
        else
        {
            /*default display am/pm time*/
            CursorPositionWindows(12, 0);
            Clock.print_am_pm();
            CursorPositionWindows(12, 11);
        }
        ++Clock;
        mtx.unlock();
        Sleep(1000);
    }
}

int Get_Time(void)
{
    int hour = 0, minute = 0;

    do
    {
        system("cls");
        std::cin.clear();                                                   /*clear failed status of cin*/
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /*ignore all of the user input*/
        std::cout << "Please enter the hour in 24 hour format: " << std::endl;
        std::cin >> hour;
        std::cout << "Please enter the minute: " << std::endl;
        std::cin >> minute;
    } while (std::cin.fail());

    system("cls");

    return ((hour * Seconds_IN_HOUR) + (minute * SECONDS_IN_MINUTE));
}

void CursorPositionWindows(short int x, short int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    
    COORD position = {x, y};

    SetConsoleCursorPosition(hStdout, position);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}