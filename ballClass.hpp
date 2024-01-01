#ifndef BALLCLASS_HPP
#define BALLCLASS_HPP

#include <raylib.h>
#include <raymath.h>

class ballClass {
public:
    ballClass () {}
    ballClass(const Vector2& position, const Vector2& direction, const float& radius): 
        position(position), 
        direction(direction),
        radius(radius)
    {}
    void move(){
        position = Vector2Add(position, direction);
    }
    void checkRectangleCollision(){
    }
    Vector2 position;
    Vector2 direction;
    float radius;
};

#endif
