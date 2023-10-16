#include<iostream>

using namespace std;


long hms_to_secs(int &hours,int &minutes,int &seconds)
{
   long sec=0;
   sec = (long)((hours*3600)+(minutes*60)+seconds);
   return sec;
}
int main()
{
    int h,m,s;
    long total=0;
    char c='2';
    cout<<"enter time in h:m:s format"<<endl;
    cin>>h>>c>>m>>c>>s;
    cout<<endl;
    cout<<"entered time is : "<<h<<c<<m<<c<<s<<endl;
    total=hms_to_secs(h,m,s);

    cout<<"total number of seconds ="<<total;

}