#ifndef GRAHAMSCANNER_HPP
#define GRAHAMSCANNER_HPP

#include "core/reference.h"

#include "core/math/vector2.h"
#include "core/array.h"

#include <vector>





class GrahamScanner : public Reference
{
    GDCLASS(GrahamScanner, Reference);

    std::vector<Vector2> m_Points;
    Vector2 m_FirstPoint;
    bool m_Unset = true;

protected:
    static void _bind_methods();
public:
    GrahamScanner() = default;

    void insertPoint(float x, float y);
    Array calculateHull();
};

#endif // GRAHAMSCANNER_HPP
