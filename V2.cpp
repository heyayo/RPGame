#include "V2.hpp"
#include "Math.hpp"

V2::V2(int a, int b) : x(a), y(b) {}
V2::~V2() {}

V2& V2::operator+=(V2& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

int V2::Length()
{
    return Root(x*x + y*y);
}

bool V2::operator==(V2 &rhs)
{
    return (x == rhs.x && y == rhs.y);
}


