#include<iostream>
#include<string>

using namespace std;


void Format(string& st)
{
    int i=0,j=0;
    int l=st.length();
    for(i=l , j=0 ; i >= 0 ; j++ , i--)
    {
        if( ( (j%3)== 0 ) && ( i != l ) && ( i != 0 ) ) // put ',' every third pos and it's not a start and not the end
        st.insert(i,",");
    }
}

int main(void)
{
    string stIO;

    cout<<"enter the string: "; 
    cin>>stIO;
    Format(stIO);
    cout<<stIO<<endl;
}