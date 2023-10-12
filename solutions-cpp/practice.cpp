#include <iostream>
#include <string>

using namespace std;
int g = 10;

class cCounter
{
    public:

        cCounter(int start_count=0, int step=1):
                        m_count(start_count),
                        m_step(step)
        {}

         
        cCounter& increment()
        { 
            this->m_count++; 
            return (*this) ; // ??
        }

        cCounter& decrement()
        { 
            m_count--; 
            return (*this) ;
        }
        
        int count(){ return m_count; }

        cCounter operator ++ () //increment (prefix)
        {
            m_count+=m_step;
            // cCounter temp_counter(m_count);
            // return temp_counter;
            return cCounter(m_count);
        }

        cCounter operator -- () //increment (prefix)
        {
            m_count-- ;
        }


    private:
        int m_count;
        int m_step;
};

template <class T1, class T2>
class TemplateExample
{
  public:
    TemplateExample(T1 d):m_data(d){}
    void print(){std::cout << "I iam " << m_data << std::endl ; }  
  private:
    T1 m_data;
};


class A
{
public:
    A(int a):m_A(a){}
    int getA()
    {
        return m_A;
    }

private:
    int m_A;
};


class B: public A
{
public:
    B(int b):
    A(b),
    m_B(b){}
    int getA()
    {
        return m_B;
    }

private:
    int m_B;
};

class C: public A
{
public:
    C(int c):
    A(c),
    m_C(c){}
    int getA()
    {
        return m_C;
    }

private:
    int m_C;
};

////////////////////////////////////////////////////////////////
class Base //base class
{
public:
virtual void show() //normal function
{ cout << "Base\n"; }
};
////////////////////////////////////////////////////////////////
class Derv1 : public Base //derived class 1
{
public:
void show()
{ cout << "Derv1\n"; }
};
////////////////////////////////////////////////////////////////
class Derv2 : public Base //derived class 2
{
public:
void show()
{ cout << "Derv2\n"; }
};




// setter and getter at the same time
int& modifyG()
{  
    return g;
}

void func3(int*& addr)
{
    std::cout << addr;
}

void func(int a)
{
    std::cout << "a + 10 = " << (a+10) << std::endl;
}

void func(char c)
{
    std::cout << "This is a charachter " << c << std::endl;
}

template <class T>
T add(T a, T b)
{
    return a+b;
}


int main(void)
{

    // std::string str;
    // char line[1000] = {0} ; // c style string (Byte Array)
    // std::cin.getline(line, 1000);

    // str = std::string(line); // This is not casting

    // std::cout << " you entered: \n" << str ;

    // func(15);
    // func('M');
    
    // cCounter c1,c2;

    // // copy constructor
    // c2 = ++c1;
    // ++c1;
    // ++c1;
    // --c1;
    // cCounter c1;// m_count = 0, step = 1
    // ++c1;
    // cCounter c2(5);// m_count = 5, step = 1;
    // ++c2;
    // cCounter c3(0,2); // m_count = 0, step = 2
    // ++c3;

    // std::cout << c1.count() << " " << c2.count() << " " << c3.count() <<std::endl;

    // std::cout << "counter value: " << c1.count() << std::endl ;

    // A a(3);
    // std::cout << "A = " << a.getA() << std::endl;

    // B b(10);
    // std::cout << "B = " << b.getA() << std::endl;
    
    // C c(15);
    // std::cout << "C = " << c.getA() << std::endl;
    
    // A* p2A ;
    // // std::cout << "p2A = " << p2A->getA() << std::endl;

    // p2A = &b;
    // std::cout << "p2A = " << p2A->getA() << std::endl;

    // p2A = &c;

    // std::cout << "p2A = " << p2A->getA() << std::endl;
    // Derv1 dv1; //object of derived class 1
    // Derv2 dv2; //object of derived class 2
    // Base* ptr; //pointer to base class
    // ptr = &dv1; //put address of dv1 in pointer
    // ptr->show(); //execute show()
    // ptr = &dv2; //put address of dv2 in pointer
    // ptr->show(); //execute show()

    // cout << add(5,6) << " " << add(5.5,6.25) ;

    TemplateExample<int> ex1(10) ;
    ex1.print();

    TemplateExample<float> ex2(20.25) ;
    ex2.print();

    TemplateExample<string> ex3("Mazen") ;
    ex3.print();





    return 0;
}