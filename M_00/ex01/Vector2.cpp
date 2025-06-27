#include "Vector2.hpp"

Vector2::Vector2(int x, int y) {
    if (x < 0 || y < 0) {
        throw std::runtime_error("Coordinates cannot be negative");
    }
    _x = x;
    _y = y;
}

int Vector2::getX() const { return _x; }
int Vector2::getY() const { return _y; }


std::ostream& operator<<(std::ostream& os, const Vector2& v) {
    os << "Vector2(" << v._x << ", " << v._y << ")";
    return os;
}