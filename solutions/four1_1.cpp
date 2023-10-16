//creating operator overloading methods using operator keyword
#include<iostream>

using namespace std;

class counter
{
    private:
        int count;
    public:
        counter():count(0)
        {
        }
        int getCount(){
            return count;
        }
        void operator ++(){
            count++;
        }
        void operator --(){
            count--;
        }

};
int main()
{
    counter c1;
    ++c1;
    --c1;
    ++c1;
    ++c1;
    --c1;
    ++c1;
    ++c1;
    --c1;
    cout<<"counter equals :"<<c1.getCount()<<endl;

}