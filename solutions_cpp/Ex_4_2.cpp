#include<iostream>
using namespace std;


class cCounter
{
    private:
    int m_count;
    int m_step;

    public:
    cCounter(void):m_count(0),m_step(1)
    {

    }
    cCounter(int StartValue,int step=1):m_count(StartValue),m_step(step)
    {

    }
    cCounter operator++(void)//increment (prefix)
    {
        m_count+=m_step;
        // cCounter temp_counter(m_count);
        // return temp_counter;
        return cCounter(m_count);
    }
    cCounter operator--(void)
    {
        m_count-=m_step;
        return cCounter(m_count);
    }

    void Display(void)
    {
        cout<< "value = " <<m_count<<endl;
    }
};
int main(void)
{
    cCounter c1(0,1);
    cCounter c2;
    ++c1;
    ++c1;
    c2=--c1;
    c2.Display();

    return 0;
}