#include <iostream>
using namespace std;

class Cartesian
{
private:
int x_Direction;
int y_Direction;

public:
Cartesian(int x , int y): x_Direction(x) , y_Direction(y){}

void Set_x_y(int m_x_Direction, int m_y_Direction)
{
    x_Direction = m_x_Direction;

    y_Direction = m_y_Direction;
}
void Display()
{
cout<<x_Direction << endl << y_Direction<<endl;
}



};
int main()
{

    return 0;
}

cCartesianddCoordinates(cCartesian& rhs)
{
return cCartesian((m_x + rhs.m_x),(m_y + rhs .m—y));
}