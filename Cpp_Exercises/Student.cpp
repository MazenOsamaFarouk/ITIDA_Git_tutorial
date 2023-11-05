#include <Student.hpp>


Student::Student():
m_age(0),
m_name(""),
m_class(Class_A)
{} // default constructor

Student::Student(std::string name, int age, Class c ):
m_age(age),
m_name(name),
m_class(c)
{}

int& Student::Age(){ return m_age; }
std::string& Student::Name( ){ return m_name; }
int& Student::StudentClass() { return m_class; }

std::string Student::ClassToString(int c)
{
    switch(c)
    {
        case Class_A:
            return "Class_A" ;
        break;

        case Class_B:
            return "Class_A" ;
        break;
        case Class_C:
                        return "Class_A" ;
                    break;
        case Class_D:
                        return "Class_A" ;
                    break;
        case Class_E:
                        return "Class_A" ;
                    break;
        case Class_F:
                        return "Class_A" ;
                    break;
    }
}

std::string Student::Print()
{
    std::stringstream ss;
    ss << m_age ; // equivalent to std::to_string(m_age)
    std::string output;
    output = m_name + "," + ss.str() + "," + ClassToString(m_class) + "\n"; // "Class_A"
    return output;
}

