/*
 * ex6.cpp
 *
 *  Created on: Oct 6, 2023
 *      Author: HP
 */

#include<iostream>
#include<string.h>

using namespace std;


int main()
{

    string num;
    cin>>num;

    for(int i=num.size(),j=0;i>=0;i--,j++)
    {
    	if(j%3==0 && i!=0 && i!=num.size())
    	{
    		num.insert(i,",");
    	}

    }
    cout<<num<<endl;

	return 0;
}


