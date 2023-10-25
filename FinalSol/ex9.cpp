#include<iostream>

using namespace std;

class cCartersian
{
    private:
        int m_x;
        int m_y;
    public:
        cCartersian(int _x=0, int _y=0):m_x(_x), m_y(_y) {  }
        
        int& xSetGet()
        {
            return m_x;
        }

        int& ySetGet()
        {
            return m_y;
        }

        cCartersian AddCordinates(cCartersian& rhs)
        {
            return cCartersian( ( m_x + rhs.m_x ), ( m_y + rhs.m_y ) );
        }

        cCartersian operator+(cCartersian& rhs)
        {
            return cCartersian( ( m_x + rhs.m_x ), ( m_y + rhs.m_y ) );
        }

        void Display_Cordinates(void)
        {
            cout<<"x : "<<m_x<<endl<<"y : "<<m_y<<endl;
        }


};


int main(void)
{
    cCartersian p1(5,2), p2(3,6),p3;

    p3 = p1.AddCordinates(p2);
    cCartersian p4 = p1 + p3;
    p3.Display_Cordinates(); p4.Display_Cordinates();
}

pt2;;