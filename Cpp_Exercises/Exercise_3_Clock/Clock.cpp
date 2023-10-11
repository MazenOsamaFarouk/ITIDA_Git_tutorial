#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <mutex>
#include <atomic>

/*
  This made me hate windows using linux would have been so much easier
  using non blocking methods to take input from user would have been
  great like ncurses.  Also this is not portable at all and not thread safe.
*/

#define SECONDS_IN_A_DAY 86400
#define SECONDS_IN_HALF_DAY 43200
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

enum MenuChoices
{
    kSet = 's',
    kReset = 'r',
    kAmPm = '1',
    kTwentyFour = '2',
    kExit = 'e'
};

class CTime
{
private:
    bool reset_;
    int time_in_seconds_;
    unsigned short int hours_;
    unsigned short int minutes_;
    unsigned short int seconds_;

    bool FormatAndSave(int copy_time_in_seconds)
    {
        if (copy_time_in_seconds > 0 && copy_time_in_seconds < SECONDS_IN_A_DAY)
        {
            time_in_seconds_ = copy_time_in_seconds;
            hours_ = copy_time_in_seconds / SECONDS_IN_HOUR;
            copy_time_in_seconds = copy_time_in_seconds % SECONDS_IN_HOUR;
            minutes_ = copy_time_in_seconds / SECONDS_IN_MINUTE;
            copy_time_in_seconds = copy_time_in_seconds % SECONDS_IN_MINUTE;
            seconds_ = copy_time_in_seconds;
            reset_ = false;
        }
        else /*cases: 1-Got a wrong input resetting to 0:0:0. 2-While passing time reached 23:59:59,so next count will reset to 0:0:0*/
        {
            hours_ = 0;
            minutes_ = 0;
            seconds_ = 0;
            time_in_seconds_ = 0;
            reset_ = true;
        }
        return reset_;
    }

public:
    CTime() : reset_(false),
              hours_(0),
              minutes_(0),
              seconds_(0),
              time_in_seconds_(0)
    {
        /*do nothing*/
    }

    bool SetTimeSeconds(int copy_time_in_seconds)
    {
        return FormatAndSave(copy_time_in_seconds);
    }

    bool SetTime(int copy_hours, int copy_minutes, int copy_seconds)
    {
        return FormatAndSave(((copy_hours * SECONDS_IN_HOUR) + (copy_minutes * SECONDS_IN_MINUTE) + (copy_seconds)));
    }

    CTime operator++(int)
    {
        CTime temp = *this;
        time_in_seconds_++;
        FormatAndSave(time_in_seconds_);
        return temp;
    }

    CTime operator++(void)
    {
        ++time_in_seconds_;
        FormatAndSave(time_in_seconds_);
        return (*this);
    }

    bool ResetCheck(void) const
    {
        return reset_;
    }

    void ResetTime(void)
    {
        SetTimeSeconds(0);
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

    void Print(void) const
    {
        std::cout << std::setw(2) << std::setfill('0') << hours_
                  << ":"
                  << std::setw(2) << std::setfill('0') << minutes_
                  << ":"
                  << std::setw(2) << std::setfill('0') << seconds_;
    }

    void PrintAmPm(void) const
    {
        int temp_hours = 0;
        if (time_in_seconds_ >= SECONDS_IN_HALF_DAY)
        {
            if (hours_ > 12)
            {
                temp_hours = hours_ - 12;
                std::cout << std::setw(2) << std::setfill('0') << temp_hours
                          << ":"
                          << std::setw(2) << std::setfill('0') << minutes_
                          << ":"
                          << std::setw(2) << std::setfill('0') << seconds_
                          << " PM";
            }
            else
            {
                std::cout << std::setw(2) << std::setfill('0') << hours_
                          << ":"
                          << std::setw(2) << std::setfill('0') << minutes_
                          << ":"
                          << std::setw(2) << std::setfill('0') << seconds_
                          << " PM";
            }
        }
        else
        {
            if (hours_ == 0)
            {
                temp_hours = 12;
                std::cout << std::setw(2) << std::setfill('0') << temp_hours
                          << ":"
                          << std::setw(2) << std::setfill('0') << minutes_
                          << ":"
                          << std::setw(2) << std::setfill('0') << seconds_
                          << " AM";
            }
            else
            {
                std::cout << std::setw(2) << std::setfill('0') << hours_
                          << ":"
                          << std::setw(2) << std::setfill('0') << minutes_
                          << ":"
                          << std::setw(2) << std::setfill('0') << seconds_
                          << " AM";
            }
        }
    }
};

void Thread1ReadUserInput(void);
void Thread2DisplayClock(void);
void Thread3IncrementClock(void);

void DisplayMenu(void);
int GetTime(bool reset);

void ShowConsoleCursor(bool show_flag);
void CursorPositionWindows(short int x, short int y);

CTime clock_;
std::mutex console_mutex_;
std::atomic<bool> am_pm_format(true); /*set default format from here true for am/pm false for 24 hour format*/
char user_input(0);

int main(void)
{
    ShowConsoleCursor(false);
    DisplayMenu();

    std::thread input(Thread1ReadUserInput);
    std::thread display(Thread2DisplayClock);
    std::thread increment(Thread3IncrementClock);

    input.join();
    display.join();
    increment.join();

    system("cls");
    std::cout << "Bye." << std::endl;

    return 0;
}

void DisplayMenu(void)
{
    system("cls");
    CursorPositionWindows(0, 1);
    clock_.DisplayHelpList();
}

void Thread1ReadUserInput(void)
{
    while (true)
    {
        if (_kbhit())
        {
            console_mutex_.lock();
            user_input = getch();
            tolower(user_input);
            console_mutex_.unlock();

            switch (user_input)
            {
            case kSet:
            {
                console_mutex_.lock();
                bool reset = false;
                do
                {
                    reset = clock_.SetTimeSeconds(GetTime(reset));
                } while (reset);
                console_mutex_.unlock();
            }
            break;
            case kReset:
                clock_.ResetTime();
                break;
            case kAmPm:
                am_pm_format = true;
                break;
            case kTwentyFour:
                am_pm_format = false;
                break;
            case kExit:
                return;
                break;
            default: /*do nothing*/
                break;
            };
            console_mutex_.lock();
            DisplayMenu();
            console_mutex_.unlock();
        }
    }
    Sleep(50);
}

void Thread2DisplayClock(void)
{
    while (user_input != kExit)
    {
        console_mutex_.lock();
        CursorPositionWindows(12, 0);
        if (am_pm_format)
        {
            clock_.PrintAmPm();
        }
        else
        {
            clock_.Print();
        }
        console_mutex_.unlock();
        Sleep(50);
    }
}

void Thread3IncrementClock(void)
{
    while (user_input != kExit)
    {
        ++clock_;    /*increment 1 second*/
        Sleep(1000); /*wait 1 second*/
    }
}

int GetTime(bool reset)
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
                  << "If its \'Pm\' and not 12 Pm." << '\n'
                  << "just \"add 12 to your current time\"." << '\n'
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

    return ((hour * SECONDS_IN_HOUR) + (minute * SECONDS_IN_MINUTE));
}

void ShowConsoleCursor(bool show_flag)
{
    HANDLE h_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;

    GetConsoleCursorInfo(h_stdout, &cursor_info);
    cursor_info.bVisible = show_flag; // set the cursor visibility
    SetConsoleCursorInfo(h_stdout, &cursor_info);
}

void CursorPositionWindows(short int x, short int y)
{
    HANDLE h_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursor_position = {x, y}; // change x y position

    SetConsoleCursorPosition(h_stdout, cursor_position);
}