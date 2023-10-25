#include<iostream>

using namespace std;


class cTime
{
    private:
        int m_hours;
        int m_mins;
        int m_secs;
    public:
        // cTime():m_hours(0),m_mins(0),m_secs(0) { }
        cTime(int init_hr=0, int init_min=0, int init_sec=0):m_hours(init_hr),m_mins(init_min),m_secs(init_sec)
        {
            
        }

        // cTime(cTime&  obj)
        // {
        //      m_hours=obj.m_hours;  m_mins=obj.m_mins;  m_secs=obj.m_secs;
        // }

        void Display(void) const
        {
            cout<<m_hours<<":"<<m_mins<<":"<<m_secs<<endl;
        }
            //using operator overloading
        cTime operator+(cTime& obj2) 
            {
               return cTime( ( this->m_hours + obj2.m_hours ) , ( this->m_mins + obj2.m_mins ) , ( this->m_secs + obj2.m_secs ) );
            }
        
        void Add(cTime& obj2)
        {
            m_hours+=obj2.m_hours;  m_mins+=obj2.m_mins;  m_secs+=obj2.m_secs;
        }

        long int operator++(void)
        {
            return ( (m_hours * 60 *60) + (m_mins * 60) + (m_secs) );
        }

        long int operator--(void)
        {
            return ( (m_hours * 60 *60) + (m_mins * 60) + (m_secs) );
        }

        void ShowSecCount(void) 
        {
            // long secs = ++ob;
            cout<<"time counted = "<<--(*this)<<" secs"<<endl;
        }
};




int main(void)
{

    cTime t1(1,2,3);
    cTime t2(5,5,5);
    cTime t3;
    t3 = t1 + t2;
    t3.Display();
    t3.ShowSecCount();
    t2.ShowSecCount();
    return 0;
}