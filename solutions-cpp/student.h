#pragma once
#include<iostream>
#include<fstream>
#include<strstream>
#include<string>
class CsvReader
{
public:
void read();
};
class student : public CsvReader
{
int age;
std:: string name;
int cls;
public:
void print(){};
};
