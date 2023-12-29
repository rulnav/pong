#include <raylib.h>

const int screenWidth = 800;
const int screenHeight = 450;

struct ball {
    Vector2 position;
    Vector2 direction;
    float radius;
}ball;
void processInput(){
    //process player input
}
void updateState(){
    //update game state
}
void setup(){
    //setup initial game state
    ball.position = { (float)screenWidth/2, (float)screenHeight/2 };
    ball.radius = 25;
}
void render(){
    //render image
}
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    setup();
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        // if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        // if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        // if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            DrawCircleV(ball.position, ball.radius, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
