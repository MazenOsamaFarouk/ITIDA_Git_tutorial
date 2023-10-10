#include <iostream>

using namespace std ;


class SelfCounting
{
   static  int counter;
    int number ;

    public:
    SelfCounting() 
    {
        number = ++counter;
    }

    void PrintObjNumber()
    {
        cout << "Iam object number "<<number<<endl;
    }

    static void PrintObjCount()
    {
         cout << counter<<endl;
    }
};

int SelfCounting :: counter = 0;

int main()
{
    SelfCounting s1;
    SelfCounting :: PrintObjCount();

    SelfCounting s2,s3;
    SelfCounting :: PrintObjCount();

    s1.PrintObjNumber();    
    s2.PrintObjNumber();    
    s3.PrintObjNumber();



    return 0;
}