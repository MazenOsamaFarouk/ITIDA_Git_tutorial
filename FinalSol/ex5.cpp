#include<iostream>

using namespace std;

class cSelfCount
{
    private:
        static int IDcouter;
        int SerialNumber;
        int m_Data;
    public:
        cSelfCount(int initData=0):m_Data(initData)
        {
            SerialNumber = IDcouter++;
        }

        void Display(void) const
        {
            cout<<"Im object number "<<SerialNumber<<endl;
            cout<<"My data = "<<m_Data<<endl;
        }

};
int cSelfCount::IDcouter=0;

int main(void)
{
    cSelfCount ob1;
    cSelfCount ob2(4);
    cSelfCount ob3(7);

    ob1.Display(); ob2.Display(); ob3.Display();
    return 0;
}