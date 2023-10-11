#include <iostream>

class Cartesian
{
private:
    double x;
    double y;

public:
    Cartesian(double x = 0, double y = 0) : x(x),
                                            y(y)
    {
        /*do nothing*/
    }

    double getX() const
    {
        return x;
    }

    double get_Y() const
    {
        return y;
    }

    void set_X(double number)
    {
        x = number;
    }

    void set_Y(double number)
    {
        y = number;
    }
};
