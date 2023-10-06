#include <iostream>
using namespace std;

long hms_to_secs(int hrs, int mins, int secs);

int main()
{
    char ch, temp;
    int hrs, mins, secs;
    
    while(true)
    {
        cout << "Enter time (HH:MM:SS): ";
        cin >> hrs >> temp >> mins >> temp >> secs;
        long totalSec = hms_to_secs(hrs, mins, secs);
        cout << "Total seconds: " << totalSec << endl;

    }
    cout << "\nExit"<< endl;
    return 0;
}

long hms_to_secs(int hrs, int mins, int secs){
    long totalSecs = 3600 * hrs + 60 * mins + secs;
    return totalSecs;
}