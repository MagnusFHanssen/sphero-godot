#include "spheroparser.hpp"

bool SpheroParser::openFile(const String p_FileName)
{
    std::string fileName(p_FileNamec_str());
    m_FileIn.open(fileName);
    m_FileLoaded = m_FileIn.is_open();
    return m_FileLoaded;
}

String SpheroParser::readLine()
{
    if(m_FileLoaded && !m_FileIn.eof()){
        std::string line;
        m_FileIn >> line;
        std::cout << line;
        return line.c_str();
    }
    return "EOF";
}

void SpheroParser::_bind_methods(){
    ClassDB::bind_method(D_METHOD("open_file", "path"), &SpheroParser::openFile);
    ClassDB::bind_method(D_METHOD("read_line"), &SpheroParser::readLine);
}
