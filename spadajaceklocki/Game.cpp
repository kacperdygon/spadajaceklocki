#include "Game.h"
#include "constants.cpp"
#include <iostream>

Game::Game()
{

}

void Game::Update()
{
    if (spawnBlocks) SpawnBlock();
    for (int i = 0; i < blocks.size(); i++) {
        blocks[i]->Update();
        if (blocks[i]->CheckIfOutOfBounds()) {
            blocks.erase(blocks.begin() + i);
        }
    }
    platform.Update();

    CheckPlatformBlockCollision();

    UpdateStartButton();
}

void Game::Render()
{
    for (auto& entity : blocks) {
        entity->Render();
    }
    platform.Render();

    DrawStartButton();
    DrawScore();
    
}

void Game::SpawnBlock() {
    float probability = static_cast<float>(1) * Constants::BLOCKS_PER_SEC * GetFrameTime();
    float randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
    if ( randomFloat < probability ) {
        auto newBlock = blockSpawner.SpawnBlock();
        blocks.push_back(std::make_unique<Block>(newBlock));
    }
}

void Game::CheckPlatformBlockCollision()
{
    for (int i = 0; i < blocks.size(); i++) {

        Rectangle blockShape = blocks[i]->GetShape();
        Rectangle platformShape = platform.GetShape();

        bool collisionY = blockShape.y < platformShape.y && blockShape.y + blockShape.height > platformShape.y;
        bool collisionX = blockShape.x + blockShape.width > platformShape.x && blockShape.x < platformShape.x + platformShape.width;

        if (collisionY && collisionX) {
            blocks.erase(blocks.begin() + i);
            score++;
        }
    }
}

void Game::UpdateStartButton()
{
    if (CheckCollisionPointRec(GetMousePosition(), { 0, 0, 100, 20 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        spawnBlocks = true;
    }
}

void Game::DrawStartButton()
{
    if (!spawnBlocks) {
        DrawRectangle(0, 0, 100, 20, RED);
        DrawText("Start", 0, 0, 20, WHITE);
    }
    
}

void Game::DrawScore()
{
    DrawText(TextFormat("Score: %d", score), 0, 20, 20, BLACK);
}