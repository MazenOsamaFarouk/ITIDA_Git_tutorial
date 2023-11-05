#pragma once

#include <iostream>
#include <fstream>
#include <sstream>


#define MAX_LINES   100
#define MAX_CHARS_PER_LINE   1000

struct FileContentsArr_t
{
    std::string arr[MAX_LINES];
};



class CsvReader
{
public:
    CsvReader(std::string file_path);

    void read(); // read enitre file contents
   
    void write(); // write entire file contents
    
    FileContentsArr_t getContents();
    
    int getFileSize();
    

private:
    std::fstream m_file;
    FileContentsArr_t m_file_contents ;
    unsigned int m_file_no_lines;

};
