#ifndef BALLCLASS_HPP
#define BALLCLASS_HPP

#include <raylib.h>
#include <raymath.h>
#include "constants.hpp"

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
        checkWallCollision();
    }
    void checkWallCollision(){
        if( (position.y+radius >= screenHeight-1.0 ) ||
            (position.y-radius <= 1.0 ) ){
            direction.y = -direction.y;
        }
    }
    bool checkGoal(){
    
    }
    void checkRectangleCollision(){
    }
    Vector2 position;
    Vector2 direction;
    float radius;
};

#endif
