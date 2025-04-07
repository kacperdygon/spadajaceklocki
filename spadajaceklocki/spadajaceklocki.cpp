// spadajaceklocki.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "raylib.h"
#include "BlockSpawner.h"
#include <ctime>
#include "constants.cpp"
#include "Game.h"

int main()
{

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "kloce");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {

        game.Update();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        game.Render();

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}