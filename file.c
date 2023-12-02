#include <stdio.h>
#include <unistd.h>


enum TrafficLightColor 
{
    Red,
    Yellow,
    Green
};

int main() 
{
    enum TrafficLightColor currentColor = Red;

    while (1) 
    {
        if (currentColor == Red) 
        {
            sleep(30);
            currentColor = Yellow;
            printf("the current light is yellow\n");
        } 
        else if (currentColor == Yellow) 
        {
            sleep(30);
            currentColor = Green;
            printf("the current light is green\n");
        } 
        else if (currentColor == Green) 
        {
            sleep(35); 
            currentColor = Red;
            printf("the current light is red\n");
        }
    }

    return 0;
}