#include "Vector2.hpp"

Vector2::Vector2(int x, int y) : _x(x), _y(y) {}

int Vector2::getX() const { return _x; }
int Vector2::getY() const { return _y; }

void Vector2::set(int x, int y) {
    _x = x;
    _y = y;
}

std::ostream& operator<<(std::ostream& os, const Vector2& v) {
    os << "Vector2(" << v._x << ", " << v._y << ")";
    return os;
}