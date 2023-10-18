//usage of static keyword
#include<iostream>

using namespace std;

class object_Counting
{
    private:
    int serial;
    static int total_objects;
    public:
    //constructor with no args
    object_Counting()
    {
        ++total_objects;
        serial=total_objects;
    }
    ~object_Counting() //destructor
    {
        total_objects--;
        cout << "Destroying serial no. " << serial << endl;
    }
    void showSerial()
    {
        cout<<"I am object number "<<serial<<endl;
    }
    static void showTotal()
    {
        cout<<"total objects created : "<<total_objects<<endl;
    }
};

int object_Counting :: total_objects =0;
int main(void)
{
    object_Counting obj1;
    obj1.showSerial();
    object_Counting :: showTotal();
    object_Counting obj2 ,obj3;
    object_Counting :: showTotal();
    obj1.showSerial();
    obj2.showSerial();
    obj3.showSerial();

}