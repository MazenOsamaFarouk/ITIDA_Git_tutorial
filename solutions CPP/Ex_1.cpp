#include <iostream>
using namespace std ; 

int hms_to_secs(int hours , int minutes , int seconds)
{
    long total_seconds = (hours *3600 )+ (minutes * 60 )+ seconds ;
    return total_seconds;
}

int main ()
{
    int hours,minutes,seconds;
    long total;
    char colon ; 
    while (true)
    {   
        cout<< "Enter time" <<endl;
        cin >> hours >> colon >> minutes >> colon >> seconds;
        total = hms_to_secs(hours,minutes,seconds);
        cout<< "The total seconds are :"<< total <<endl;
    }

    return 0 ;
}