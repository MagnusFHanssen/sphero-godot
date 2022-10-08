#ifndef SPHEROPARSER_HPP
#define SPHEROPARSER_HPP

#include <fstream>

#include "core/reference.h"
#include "core/ustring.h"
#include "core/math/vector3.h"

class SpheroParser : public Reference
{
    GDCLASS(SpheroParser, Reference);

    std::ifstream m_FileIn;

    Vector3 m_LastVector;
    float m_LastTime;

protected:
    static void _bind_methods();

public:
    SpheroParser() = default;

    void openFile(const String p_FileName);
    void readLine();
    bool isOpen();

    Vector3 yieldVector();
    float yiealTime();
};

#endif // SPHEROPARSER_HPP
