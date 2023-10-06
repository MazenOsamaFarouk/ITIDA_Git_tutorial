#include <iostream>

using namespace std;

#define HOURS 0
#define MINUTES 1
#define SECONDS 2

long hms_to_secs(int Copy_Hours, int Copy_Minutes, int Copy_Seconds);
bool Processing_UserInput(string UserInput, int *Hours, int *Minutes, int *Seconds);

int main(void)
{
    bool err = false;
    string Local_UserInput;
    int Local_Hours = 0, Local_Minutes = 0, Local_Seconds = 0;
    long Local_ResultInSeconds = 0;

    while (1)
    {
        /*Taking User Input*/
        cout<<endl;
        cout << "Please Enter the time in this format \"hh:mm:ss\": " << endl;
        cin >> Local_UserInput;
        /*Processing user Input*/
        err = Processing_UserInput(Local_UserInput, &Local_Hours, &Local_Minutes, &Local_Seconds);

        /*Displaying the result or error*/
        if (!err)
        {
            Local_ResultInSeconds = hms_to_secs(Local_Hours, Local_Minutes, Local_Seconds);
            cout << "Result: " << Local_ResultInSeconds << " Seconds." << endl;
        }
        else
        {
            cout << endl;
            cout << "Error Wrong Input or format you entered: " << Local_UserInput << " Please Try Again." << endl;
            err = false;
            Local_Hours = 0;
            Local_Minutes = 0;
            Local_Seconds = 0;
            Local_ResultInSeconds = 0;
        }
    }
    return 0;
}

bool Processing_UserInput(string UserInput, int *Hours, int *Minutes, int *Seconds)
{
    bool err = false;
    int Local_Iterator = 0, Number_buffer = 0, Local_Selector = 0;
    /*Processing user input*/
    while (UserInput[Local_Iterator] != '\0')
    {
        if (UserInput[Local_Iterator] >= '0' && UserInput[Local_Iterator] <= '9')
        {
            Number_buffer = (Number_buffer * 10) + (UserInput[Local_Iterator] - '0');
        }
        
        if (Local_Selector == HOURS && Number_buffer >= 0 && Number_buffer < 24)
        {
            *Hours = Number_buffer;
        }
        else if (Local_Selector == MINUTES && Number_buffer >= 0 && Number_buffer < 60)
        {
            *Minutes = Number_buffer;
        }
        else if (Local_Selector == SECONDS && Number_buffer >= 0 && Number_buffer < 60)
        {
            *Seconds = Number_buffer;
        }
        else
        {
            err = true;
        }

        if (UserInput[Local_Iterator] == ':')
        {
            Local_Selector++;
            Number_buffer = 0;
        }

        Local_Iterator++;
    }
    return err;
}

long hms_to_secs(int Copy_Hours, int Copy_Minutes, int Copy_Seconds)
{
    return (Copy_Hours * 60 * 60) + (Copy_Minutes * 60) + (Copy_Seconds);
}
