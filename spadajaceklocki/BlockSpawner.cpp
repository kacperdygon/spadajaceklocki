#include "BlockSpawner.h"
#include "Block.h"
#include "constants.cpp"



Block BlockSpawner::SpawnBlock() {
	
	Color color = { static_cast<unsigned char>(std::rand() % 256),static_cast<unsigned char>(std::rand() % 256),static_cast<unsigned char>(std::rand() % 256), 255 };

	float fallSpeed = Constants::MIN_FALL_SPEED + std::rand() % (Constants::MAX_FALL_SPEED - Constants::MIN_FALL_SPEED);

	int posX = std::rand() % (Constants::SCREEN_WIDTH - Constants::BLOCK_WIDTH);

	int posY = Constants::BLOCK_SPAWN_HEIGHT;


	Block newBlock(posX, posY, fallSpeed, color);

	return newBlock;
}