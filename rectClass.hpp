#ifndef RECTCLASS_HPP
#define RECTCLASS_HPP

#include <raylib.h>
#include <raymath.h>
#include "constants.hpp"

class rectClass {
public:
    rectClass () {}
    rectClass(const Vector2& position, const Vector2& size, const float& playerSpeed): 
        position(position), 
        size(size),
        playerSpeed(playerSpeed)
    {}
    void moveDown(){
        if(position.y+size.y >= screenHeight-1.0) return;
        position.y += playerSpeed;
    }
    void moveUp(){
        if(position.y <= 1.0) return;
        position.y -= playerSpeed;
    }
    Vector2 position;
    Vector2 size;
    float playerSpeed;
};
#endif
