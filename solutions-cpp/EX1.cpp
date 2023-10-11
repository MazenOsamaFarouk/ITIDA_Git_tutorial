#include <iostream>

using namespace std;
long hms_to_secs(int hour,int minut ,int sec){
    long time_in_sec=0;
    time_in_sec= (hour*60*60)+(minut*60)+(sec);
    return time_in_sec;
}
int main()
{ int hour=0,minut=0,sec=0;
    cout<<"enter the time "<<endl;
    cin>>hour>>minut>>sec;
    cout<<hms_to_secs(hour,minut,sec);
    return 0;
}
