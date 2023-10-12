#include <iostream>

class cCartesian
{
public:
    cCartesian(int x,int y):m_x(x),m_y(y){}
    int& x(){ return m_x; }
    int& y(){ return m_y; }

    void PrintCoordinates()
    {
        std::cout << "(" << m_x << "," << m_y << ")" << std::endl ;
    }

    cCartesian addCoordinates(cCartesian& rhs)
    {
        return cCartesian((m_x + rhs.m_x),(m_y + rhs.m_y) );
    }

    cCartesian operator +(cCartesian& rhs)
    {
        return cCartesian((m_x + rhs.m_x),(m_y + rhs.m_y) );
    }
    

private:
    int m_y;
    int m_x;
};




int main(void)
{
    cCartesian p1(2,2) , p2(6,3) ;

    cCartesian p3 = p1 + p2;

    p3.PrintCoordinates();
    

    return 0;
}