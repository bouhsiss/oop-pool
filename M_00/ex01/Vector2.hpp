#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

class Vector2 {
    private:
        int _x;
        int _y;
    public:
        Vector2(int x, int y);

        // getters
        int getX() const;
        int getY() const;


        friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
};

std::ostream& operator<<(std::ostream& os, const Vector2& v);

#endif