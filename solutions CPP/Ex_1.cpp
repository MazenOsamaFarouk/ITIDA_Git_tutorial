#include <iostream>
using namespace std;

long hms_to_secs(int hours,int mins,int secs)
{
	long totalseconds=(hours*3600)+(mins*60)+secs;
	return totalseconds;
}
int main(void)
{
	int hour,min,sec;
	char c;
	long result;
	while(true)
	{
	cout<<"Please enter the time in the form hour:min:sec"<<endl;
	cin>>hour>>c>>min>>c>>sec;
	 result = hms_to_secs(hour,min,sec);
	cout<<"time = "<<result<<" seconds";
	}
	return 0;
}
