#include <iostream>
using namespace std;

class Cartesian
{
private:
int x_Direction;
int y_Direction;
Cartesian(): x_Direction(0) , y_Direction(0){}

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