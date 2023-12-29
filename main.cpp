#include <raylib.h>
#include <raymath.h>

const int screenWidth = 800;
const int screenHeight = 450;

class ballClass {
public:
    ballClass () {}
    ballClass(const Vector2& position, const Vector2& direction, const float& radius): 
        position(position), 
        direction(direction),
        radius(radius)
    {}
    void move(){
        position = Vector2Subtract(position, direction);
    }
    Vector2 position;
    Vector2 direction;
    float radius;
}ball;
void processInput(){
    //process player input
}
void updateState(){
    //update game state
    ball.move();
}
void render(){
    //render image
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
    DrawCircleV(ball.position, ball.radius, BLUE);
    EndDrawing();
}
void setup(){
    //setup initial game state
    ball = ballClass( { (float)screenWidth/2, (float)screenHeight/2 },
          {-1.0, 0.0},
          25.0f );
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
        // if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        // if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        // if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        // if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        updateState();
        //----------------------------------------------------------------------------------

        // Draw
        render();
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
