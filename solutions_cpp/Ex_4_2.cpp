#include<iostream>
using namespace std;


class cCounter
{
    private:
    int m_count;
    int step;

    public:
    cCounter(void):m_count(0),step(1)
    {

    }
    cCounter(int x):m_count(0),step(x)
    {

    }
    void operator++(void)//increment (prefix)
    {
        m_count+=step;
    }
    void operator--(void)
    {
        m_count-=step;
    }

    void Display(void)
    {
        cout<< "value = " <<m_count<<endl;
    }
};

int main(void)
{
    // func(10); func('C');
	int n;
	cin>>n;
    cCounter c1(n);
    cCounter c2;
    c1.Display();
    ++c1;
    ++c1;
    ++c2;
    ++c2;
    ++c2;
    --c2;
    c2.Display();
    c1.Display();
    return 0;
}