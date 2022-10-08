#include "grahamscanner.hpp"

#include <algorithm>
#include <stack>

void GrahamScanner::insertPoint(float x, float y){
    if(m_Unset){
        m_FirstPoint = Vector2(x, y);
        m_Unset = false;
    }else if(m_FirstPoint.y > y){
        m_Points.push_back(m_FirstPoint);
        m_FirstPoint = Vector2(x, y);
    }else if(m_FirstPoint.y == y && m_FirstPoint.x > x){
        m_Points.push_back(m_FirstPoint);
        m_FirstPoint = Vector2(x, y);
    }else{
        m_Points.emplace_back(x, y);
    }
}

Vector2 nextPoint(std::stack<Vector2, std::vector<Vector2>>& stack){
    auto temp = stack.top();
    stack.pop();
    auto res = stack.top();
    stack.push(temp);
    return res;
}

bool counterClockwise(Vector2 const& a, Vector2 const& b, Vector2 const& c){
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) < 0.0;
}

Array GrahamScanner::calculateHull(){
    if(m_Points.size() < 3){
        return {};
    }
    // First we order:
    auto comparator = [this](Vector2 const& first, Vector2 const& second){
        return (first - m_FirstPoint).aspect() > (second - m_FirstPoint).aspect();
    };

    std::sort(m_Points.begin(), m_Points.end(), comparator);
    m_Points.push_back(m_FirstPoint);


    std::stack<Vector2, std::vector<Vector2>> stack;
    // Push first point
    stack.push(m_FirstPoint);

    for(auto point : m_Points){
        while(stack.size() > 1 && counterClockwise(nextPoint(stack), stack.top(), point)){
            stack.pop();
        }
        stack.push(point);
    }

    Array result = Array();
    while (!stack.empty()){
        result.push_back(Vector3(stack.top().x, 0.0, stack.top().y));
        stack.pop();
    }

    return result;

}

void GrahamScanner::_bind_methods(){
    ClassDB::bind_method(D_METHOD("insert_point", "x", "y"), &GrahamScanner::insertPoint);
    ClassDB::bind_method(D_METHOD("calculate_hull"), &GrahamScanner::calculateHull);
}
