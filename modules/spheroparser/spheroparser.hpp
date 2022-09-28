#ifndef SPHEROPARSER_HPP
#define SPHEROPARSER_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "core/reference.h"
#include "core/ustring.h"
//#include "vector3.h"

class SpheroParser : public Reference
{
    GDCLASS(SpheroParser, Reference);

    String readLine();

    bool m_FileLoaded;
    double m_TimeCount;
    std::ifstream m_FileIn;

    //Vector3 m_LastVec;
    //Vector3 m_NewVec;

protected:
    static void _bind_methods();

public:
    SpheroParser() = default;

    bool openFile(const String p_FileName);

};

#endif // SPHEROPARSER_HPP
