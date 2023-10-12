#include <iostream>

class cCartesian
{
private:
    double m_x;
    double m_y;

public:
    cCartesian(double x = 0, double y = 0) : m_x(m_x),
                                            m_y(m_y)
    {
        /*do nothing*/
    }

    double get_X() const
    {
        return m_x;
    }

    double get_Y() const
    {
        return m_y;
    }

    void set_X(double number)
    {
        m_x = number;
    }

    void set_Y(double number)
    {
        m_y = number;
    }

    void set_X_Y(double _x,double _y)
    {
        m_x=_x;
        m_y=_y;
    }
};

int main(void)
{

    return 0;
}