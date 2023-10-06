#include<iostream>

using namespace std;

class cCounter
{
    private:
    int count;

    public:
    cCounter():count(0)
    {

    }
    void IncrVar()
    {
        count++;
    }
    void DecVar()
    {
        count--;
    }
    void Display()
    {
        cout<<count;
    }
};

int main()
{   
    cCounter c1;
    c1.IncrVar();
    c1.IncrVar();
    c1.IncrVar();
    c1.DecVar();
    c1.Display();
    return 0;
}