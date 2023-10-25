#include<iostream>
#include<string>

using namespace std;

string* Format(string st)
{
    string ans[100];
    int start = 0,End = 0,count = 0;

    start = st.find_first_not_of(",./;:' !?><");

    while( start < st.length() )
    {   
        End = st.find_first_not_of(",./;:' !?><",start);
        ans[count]= st.substr(start,abs(start-End));
        count++;
        start=End;
        End = st.find_first_not_of(",./;:' !?><",start);
    }
    return ans;
}
asd;
int main(void)
{
    char line[1000]={0};
    string st1;
    // getline(cin,st1);
    cin.getline(line,1000);

    st1 = std::string(line); //u can say its almost casting to sting from byte array

    int start=0,End=0;
    start = st1.find_first_not_of(",./?;: ");
    while(start < st1.length() )
    {

    }

    return 0;
}