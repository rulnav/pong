#include <raylib.h>
#include <raymath.h>
#include "constants.hpp"
#include "ballClass.hpp"
#include "rectClass.hpp"

class ballClass ball;
class rectClass p1_rectangle, p2_rectangle;
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
void updateState(){
    //update game state
    ball.move();
    render();
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
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
