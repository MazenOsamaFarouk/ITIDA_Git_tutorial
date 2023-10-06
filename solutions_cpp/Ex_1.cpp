#include<iostream>

using namespace std;



long hms_to_secs(int _H,int _M, int _S)
{
    long int Total=_S;
    Total+=(_M*60);
    Total+=(_H*60*60);
    return Total;
}

int main()
{   
    int hr,min,secs,res;
    cout<<"enter hrs: ";cin>>hr;
    cout<<endl<<"enter min: ";cin>>min;
    cout<<endl<<"enter secs: ";cin>>secs;

    res=hms_to_secs(hr,min,secs);
    cout<<"secs = "<<res<<endl;
    return 0;
}