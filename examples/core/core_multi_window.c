/*******************************************************************************************
*
*   raylib [core] example - Multiple window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    int window1 = InitWindowPro(screenWidth, screenHeight, "raylib [core] example - window 1");
    int window2 = InitWindowPro(screenWidth, screenHeight, "raylib [core] example - window 2");

    SetActiveWindowContext(window1);
    SetWindowPosition(10, GetWindowPosition().y);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    Texture2D texture1 = LoadTexture("resources/wabbit_alpha.png");

    SetActiveWindowContext(window2);
    Texture2D texture2 = LoadTexture("resources/wabbit_alpha.png");
    SetWindowPosition(820, GetWindowPosition().y);
    //--------------------------------------------------------------------------------------

    Vector2 position1 = { 300,300 };
    Vector2 position2 = { 500, 300 };

    // Main game loop
   
    bool wantClose = false;

    while (!wantClose)    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        position1.x += GetFrameTime() * 100;
		position2.y += GetFrameTime() * 100;

        // Draw
        //----------------------------------------------------------------------------------
        SetActiveWindowContext(window1);
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("I am the main window", 190, 200, 20, LIGHTGRAY);

            DrawTexture(texture1, position1.x, position1.y, WHITE);
            DrawFPS(0, 0);

        EndDrawing();

        wantClose = WindowShouldClose();

        SetActiveWindowContext(window2);
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("I am the other window", 190, 200, 20, RAYWHITE);
        DrawTexture(texture2, position2.x, position2.y, WHITE);
        EndDrawing();

        wantClose = wantClose || WindowShouldClose();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    SetActiveWindowContext(window1);
    CloseWindow();        // Close window and OpenGL context

    SetActiveWindowContext(window2);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}