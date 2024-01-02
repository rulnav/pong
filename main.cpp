#include <raylib.h>
#include <raymath.h>
#include "constants.hpp"
#include "ballClass.hpp"
#include "rectClass.hpp"

class ballClass ball;
class rectClass p1_rectangle, p2_rectangle;
void changeDirectionIfWallCollision(){
    if( (ball.position.y+ball.radius >= screenHeight-1.0 ) ||
        (ball.position.y-ball.radius <= 1.0 ) ){
        ball.direction.y = -ball.direction.y;
    }
}
bool isScored(){
    if( (ball.position.x+ball.radius >= screenWidth-1.0f ) ||
        (ball.position.x-ball.radius <= 1.0f ) ){
        return true;
    }
    return false;
}
// void changeDirectionIfRectCollision(const rectClass& player){
//     if((ball.position.x+ball.radius >= player.position.x - 1.0f ) ||
//        (ball.position.x-ball.radius <= player.position.x + player.size.x + 1.0f ) &&
//        (ball.position.y <= (player.position.y + player.size.y)  ) &&
//        (ball.position.y >= player.position.y) ){
//         
//         ball.direction.x = -ball.direction.x;
//     }
// }
void changeDirectionIfp2Collision(){
    if(ball.position.x + ball.radius < p2_rectangle.position.x) return;
    if(ball.position.y < p2_rectangle.position.y) return;
    if(ball.position.y > p2_rectangle.position.y + p2_rectangle.size.y) return;
    ball.direction.x = -ball.direction.x;
}
void changeDirectionIfp1Collision(){
    if(ball.position.x - ball.radius > p1_rectangle.position.x + p1_rectangle.size.x) return;
    if(ball.position.y < p1_rectangle.position.y) return;
    if(ball.position.y > p1_rectangle.position.y + p1_rectangle.size.y) return;
    ball.direction.x = -ball.direction.x;
}
void processInput(){
    //process player input
    if (IsKeyDown(KEY_UP)) p1_rectangle.moveUp();
    else if (IsKeyDown(KEY_DOWN)) p1_rectangle.moveDown();
    if (IsKeyDown(KEY_W)) p2_rectangle.moveUp();
    else if (IsKeyDown(KEY_S)) p2_rectangle.moveDown();
}
void render(){
    //render image
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
    DrawCircleV(ball.position, ball.radius, BLUE);
    DrawRectangleV(p1_rectangle.position, p1_rectangle.size, BLUE);
    DrawRectangleV(p2_rectangle.position, p2_rectangle.size, BLUE);
    EndDrawing();
}
void setup(){
    //setup initial game state
    ball = ballClass( { (float)screenWidth/2, (float)screenHeight/2 },
          {-1.0, 1.0},
          25.0f );
    p1_rectangle = rectClass( {0.0f, 0.0f},
                              {15.0f, screenHeight/5.0f},
                              20.0f );
    p2_rectangle = rectClass( {screenWidth-15.0f, 0.0f},
                              {15.0f, screenHeight/5.0f},
                              20.0f );
    render();
}
void updateState(){
    //update game state
    ball.move();
    changeDirectionIfWallCollision();
    changeDirectionIfp1Collision();
    changeDirectionIfp2Collision();
    if(isScored()){
        setup();   
        return;
    }
    render();
}
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    setup();                        // Set up initial game state
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        processInput();
        //----------------------------------------------------------------------------------

        // Draw
        updateState();
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
        
        // check for score
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
