#include "CsvReader.hpp"


CsvReader::CsvReader(std::string file_path):
m_file(file_path.c_str(),std::fstream::in | std::fstream::out), 
m_file_no_lines(0)
{

}

void CsvReader::read() // read enitre file contents
{
    int i=0;
    while(!m_file.eof())
    {
        std::getline(m_file,m_file_contents.arr[i]);
        i++ ;
    }
    m_file_no_lines = i ;
}

void CsvReader::write() // write entire file contents
{
    for(int i=0; i< m_file_no_lines; i++)
    {
        m_file << m_file_contents.arr[i];
    }
}

FileContentsArr_t CsvReader::getContents()
{
    return m_file_contents ;
}

int CsvReader::getFileSize()
{
    return m_file_no_lines;
}


