#include<iostream>
#define SIZE 10

using namespace std;

class SafeArray{
    private:
       int arr[SIZE];
       int ret;
       bool check;

    public: 
       int& operator [](unsigned int index)
       {
        if(index<SIZE)
        {
           check = false; 
           return arr[index];
        }
        else
        {
            check=true;
            ret=-1;
            return ret;
        }
       }
       bool isError(){
        return check;
       }
       

};
int main(void){
    SafeArray a;
    for(int i=0;i<SIZE;i++)
    {
        a[i]=(i+3);
    }
    for(int i=0;i<SIZE;i++)
    {
        cout<<a[i]<<" "<<endl;
    }
    if(a.isError()){
        cout<<"index is out bounds"<<endl;

    }
    else{
        cout<<"index in bounds"<<endl;
    }

    return 0;
}