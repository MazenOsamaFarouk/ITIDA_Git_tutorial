#include<iostream>

using namespace std;

class cartesian
{
    private:
        int x;
        int y;
    public:
        cartesian(int a,int b):x(a),y(b)
        {
        }
        int& getx(){
            return x;
        }
        int& gety(){
            return y;
        }
        //cartesian addpoints(cartesian& j){
          //  return cartesian((x+j.x),(y+j.y)) ;
        //}
        //using operator overloading
        cartesian operator +(cartesian& j){
            return cartesian((x+j.x),(y+j.y)) ;
        }
        void display(){
            cout<<"("<<x<<","<<y<<")"<<endl;
        }


};
int main(void){

    cartesian p1(3,6);
    cartesian p2(2,7);
    //cartesian p3=p1.addpoints(p2);
    //syntactik sugar
    cartesian p3=p1+p2;
    p1.display();
    p2.display();
    p3.display();

    return 0;
}