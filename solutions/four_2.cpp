//example 4.2 
//defining a step value

#include<iostream>

using namespace std;

class counter
{
    private:
        int count;
        int step;
    public:
        counter(int start_count=0,int stepp=1):count(start_count),step(stepp)
        {
        }
        int getCount(){
            return count;
        }
        counter operator ++(){
            count+=step;
            return counter(count);
        }
        counter operator --(){
            count-=step;
            return counter(count);
        }

};
int main()
{
    counter c1;
    ++c1;
    ++c1;
    counter c2(4);
    ++c2;
    ++c2;
    counter c3(2,3);
    ++c3;
    ++c3;
    ++c3;


    cout<<c1.getCount()<<" "<<c2.getCount()<<" "<<c3.getCount()<<endl;

}