#include<iostream>

using namespace std;


class counter{
    private:
        int count;
    public:
        counter(){
            count=0;
        }
        void increment(){
            count++;

        }
        void decrement(){
            count--;
        }
        void display(){
        	cout<<count<<endl;
        }

};

int main(){

    counter c1;
	c1.increment();
	c1.increment();
	c1.increment();
	c1.decrement();

    c1.display();

	return 0;
}
