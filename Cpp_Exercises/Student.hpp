#pragma once

#include <iostream>
#include <string>
#include <sstream>

enum Class
{
    Class_A,
    Class_B,
    Class_C,
    Class_D,
    Class_E,
    Class_F,
    
};




class Student
{

public:
    Student();
    Student(std::string name, int age, Class c );

    int& Age();
    std::string& Name( );
    int& StudentClass();

    std::string ClassToString(int c);
    std::string Print();
    

private:
    int m_age;
    std::string m_name;
    int m_class; // A,B,C,D,F
};