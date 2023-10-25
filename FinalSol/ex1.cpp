#include<iostream>

using namespace std;

long int hms_to_secs(int _hr, int _mins, int _secs)
{
    long int TotalSecs=0;

    TotalSecs+=(_hr * 60 * 60);
    TotalSecs+=(_mins * 60 );
    TotalSecs+= _secs;

    return TotalSecs;
}

int main(void)
{
    int hr=0,min=0,sec=0;
    long int TotalSecs=0;

    cout<<"enter the time :: "<<endl;
    cin>>hr;
    cout<<hr<<":";
    cin>>min;
    cout<<hr<<":"<<min<<":";
    cin>>sec;

    TotalSecs = hms_to_secs(hr,min,sec);
    cout<<"Total secs of "<<hr<<":"<<min<<":"<<sec<<" = "<<TotalSecs<<" secs"<<endl;

    return 0;
}