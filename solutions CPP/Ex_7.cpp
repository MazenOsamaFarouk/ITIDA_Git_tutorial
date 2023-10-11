#include <iostream>
using namespace std ; 



int main ()
{
    string str[1000];
    string line ;
    getline(cin,line);
    
    int i = 0 ;
    int k = 0 ; 
    for(int j = 0 ; j < line.size(); j++)
    {
        if (line[j]==' ' || line[j]=='.' || line[j]==',' ||line[j]=='?' ||line[j]=='!' ||line[j]==':' ||line[j]==';')
        {
            str[i++]=line.substr(k , j-k);
            k = j+1;
        }
        if (i>=1000)
        {
            break;
        }
    }
    if (k < line.size())
    {
        str[i++]=line.substr(k);
    }
    for (int j = 0 ; j < i ; j++)
    {
        cout<< str[j] <<endl ;
    } 
    return 0 ;
}