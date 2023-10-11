#include <iostream>

class cCounter
{
    public:
        cCounter():m_count(0)
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
    private:
        int m_count;
};

int main()
{
    cCounter c1;

    c1.increment()
      .increment()
      .increment()
      .decrement();

    
    std::cout << c1.count() ;

    std::cout << 12 << " mazen" << 25.36 ;




    return 0;
}