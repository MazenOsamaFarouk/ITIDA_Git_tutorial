#include <iostream>
#include <iomanip>
#include <windows.h>
#include <thread>
#include <mutex>
#include <atomic>

#define SECONDS_IN_A_DAY 86400
#define SECONDS_IN_HALF_DAY 43200
#define Seconds_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

enum Menu_Choices
{
    Set = 's',
    Reset = 'r',
    Am_Pm = '1',
    TwentyFour = '2',
    Exit = 'e'
};

class c_time
{
private:
    bool reset;
    int  m_TimeInSeconds;
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
        c_time temp = *this;
        m_TimeInSeconds++;
        FormatAndSave(m_TimeInSeconds);
        return temp;
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
        std::cout << "  Welcome to Clock Program v0.0.1."       << "\n"
                  << "|---------------Help---------------|"     << "\n"
                  << "|Press \"s\" To Set Time.            |"   << "\n"
                  << "|Press \"r\" To Reset Clock.         |"   << "\n"
                  << "|Press \"1\" For Am/Pm Format.       |"   << "\n"
                  << "|Press \"2\" For 24 Hour Format.     |"   << "\n"
                  << "|Press \"e\" To Exit.                |"   << "\n"
                  << "*---------------End.---------------*"     << std::endl;
    }

    void print(void) const
    {
        std::cout << std::setw(2) << std::setfill('0') << m_hours
                  << ":"
                  << std::setw(2) << std::setfill('0') << m_minutes
                  << ":"
                  << std::setw(2) << std::setfill('0') << m_seconds;
    }

    void print_am_pm(void) const
    {
        int temp_hours = 0;
        if (m_TimeInSeconds >= SECONDS_IN_HALF_DAY)
        {
            if (m_hours > 12)
            {
                temp_hours = m_hours - 12;
                std::cout << std::setw(2) << std::setfill('0') << temp_hours
                          << ":"
                          << std::setw(2) << std::setfill('0') << m_minutes
                          << ":"
                          << std::setw(2) << std::setfill('0') << m_seconds
                          << " PM";
            }
            else
            {
                std::cout << std::setw(2) << std::setfill('0') << m_hours
                          << ":"
                          << std::setw(2) << std::setfill('0') << m_minutes
                          << ":"
                          << std::setw(2) << std::setfill('0') << m_seconds
                          << " PM";
            }
        }
        else
        {
            if (m_hours == 0)
            {
                temp_hours = 12;
                std::cout << std::setw(2) << std::setfill('0') << temp_hours
                          << ":"
                          << std::setw(2) << std::setfill('0') << m_minutes
                          << ":"
                          << std::setw(2) << std::setfill('0') << m_seconds
                          << " AM";
            }
            else
            {
                std::cout << std::setw(2) << std::setfill('0') << m_hours
                          << ":"
                          << std::setw(2) << std::setfill('0') << m_minutes
                          << ":"
                          << std::setw(2) << std::setfill('0') << m_seconds
                          << " AM";
            }
        }
    }
};

void Thread_1_ReadUserInput(void);
void Thread_2_DisplayClock(void);
void Thread_3_IncrementClock(void);

void Display_Menu(void);
int Get_Time(bool reset);

void ShowConsoleCursor(bool showFlag);
void CursorPositionWindows(short int x, short int y);

c_time Clock;
std::mutex Console_mutex;
std::atomic<bool> Am_Pm_Format(true); /*set default format from here true for am/pm false for 24 hour format*/
char user_input(0);

int main(void)
{
    ShowConsoleCursor(false);
    Display_Menu();

    std::thread Input(Thread_1_ReadUserInput);
    std::thread Display(Thread_2_DisplayClock);
    std::thread Increment(Thread_3_IncrementClock);

    Input.join();
    Display.join();
    Increment.join();

    system("cls");
    std::cout << "Bye." << std::endl;

    return 0;
}

void Display_Menu(void)
{
    system("cls");
    CursorPositionWindows(0, 1);
    Clock.DisplayHelpList();
    std::cout << "User Input: ";
}

void Thread_1_ReadUserInput(void)
{
    while (true)
    {
        std::cin >> user_input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::tolower(user_input);

        switch (user_input)
        {
        case Set:
        {
            bool reset = false;
            Console_mutex.lock();
            do
            {
                reset = Clock.Set_Time_Seconds(Get_Time(reset));
            } while (reset);
            Console_mutex.unlock();
        }
        break;
        case Reset:
            Clock.Reset_Time();
            break;
        case Am_Pm:
            Am_Pm_Format = true;
            break;
        case TwentyFour:
            Am_Pm_Format = false;
            break;
        case Exit:
            return;
            break;
        default:    /*do nothing*/
            break;
        };
        Console_mutex.lock();
        Display_Menu();
        Console_mutex.unlock();
        Sleep(150); /*just for fun*/
    }
}

void Thread_2_DisplayClock(void)
{
    while (user_input != Exit)
    {
        Console_mutex.lock();
        CursorPositionWindows(12, 0);
        if (Am_Pm_Format)
        {
            Clock.print_am_pm();
        }
        else
        {
            Clock.print();
        }
        CursorPositionWindows(0, 10);
        Console_mutex.unlock();
        Sleep(1001);
    }
}

void Thread_3_IncrementClock(void)
{
    while(user_input != Exit)
    {
        ++Clock;     /*increment 1 second*/
        Sleep(1000); /*wait 1 second*/
    }
}

int Get_Time(bool reset)
{
    int hour = 0, minute = 0;
    char buffer = 0;
    if (!reset)
    {
        system("cls");
    }
    else
    {
        std::cout << '\n'
                  << "If its \'Pm\' and not 12 Pm."                 << '\n'
                  << "just \"add 12 to your current time\"."        << '\n'
                  << "Time Can't exceed 24 hour Please Try Again. " << '\n'
                  << std::endl;
    }

    std::cout << "Please enter the current time in 24-hour format." << '\n'
              << "Please enter the Hour \"HH\" (0 to 23): ";
    std::cin >> hour;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter the Minute \"MM\" (0 to 59): ";
    std::cin >> minute;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return ((hour * Seconds_IN_HOUR) + (minute * SECONDS_IN_MINUTE));
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;

    GetConsoleCursorInfo(hStdout, &CursorInfo);
    CursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(hStdout, &CursorInfo);
}

void CursorPositionWindows(short int x, short int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Cursor_Position = {x, y}; // change x y position

    SetConsoleCursorPosition(hStdout, Cursor_Position);
}