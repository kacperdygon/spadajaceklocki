#pragma once
#include <vector>
#include "Entity.h"
#include "BlockSpawner.h"
#include <memory>
#include "Platform.h"
class Game : Entity
{
private:
	bool spawnBlocks = false;

	int score = 0;

	BlockSpawner blockSpawner;
	Platform platform;

	std::vector<std::unique_ptr<Block>> blocks;

public:

	Game();

	void Update() override;
	void Render() override;

	void SpawnBlock();

	void CheckPlatformBlockCollision();

	void UpdateStartButton();

	void DrawStartButton();
	void DrawScore();
};

