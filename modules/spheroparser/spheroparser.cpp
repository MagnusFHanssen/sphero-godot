#include "spheroparser.hpp"

#include <string>
#include <sstream>

void SpheroParser::openFile(const String p_FileName)
{
    std::string fileName(p_FileName.utf8().get_data());
    m_FileIn.open(fileName);
    m_LastVector.zero();
    m_LastTime = 0.0f;
}

void SpheroParser::readLine()
{
    std::string line;
    if(isOpen() && std::getline(m_FileIn, line)){
        std::stringstream inStream(line);
        std::string substr;
        std::getline(inStream, substr, ',');

        m_LastTime = strtof(substr.c_str(), nullptr);

        size_t i = 0;
        while(i < 3 && std::getline(inStream, substr, ',')){
            m_LastVector[i] = strtof(substr.c_str(), nullptr);
            i++;
        }
    }else{
        m_FileIn.close();
    }
}

bool SpheroParser::isOpen(){return m_FileIn.is_open();}

Vector3 SpheroParser::yieldVector(){return m_LastVector;}

float SpheroParser::yiealTime(){return m_LastTime;}

void SpheroParser::_bind_methods(){
    ClassDB::bind_method(D_METHOD("open_file", "path"), &SpheroParser::openFile);
    ClassDB::bind_method(D_METHOD("read_line"), &SpheroParser::readLine);
    ClassDB::bind_method(D_METHOD("is_open"), &SpheroParser::isOpen);
    ClassDB::bind_method(D_METHOD("yield_vector"), &SpheroParser::yieldVector);
    ClassDB::bind_method(D_METHOD("yield_time"), &SpheroParser::yiealTime);
}
