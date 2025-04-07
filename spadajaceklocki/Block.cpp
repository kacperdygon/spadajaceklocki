#include "Block.h"
#include "constants.cpp"


Block::Block(int posX, int posY, float fallSpeed, Color color)
{
	shape.x = posX;
	shape.y = posY;
	shape.width = Constants::BLOCK_WIDTH;
	shape.height = Constants::BLOCK_HEIGHT;
	this->fallSpeed = fallSpeed;

	this->color = color;
}

Block::~Block()
{
}

void Block::Update()
{
	shape.y += fallSpeed * GetFrameTime();
}

void Block::Render()
{
	DrawRectangleRec(shape, color);

}

Rectangle Block::GetShape()
{
	return shape;
}

bool Block::CheckIfOutOfBounds()
{
	if (shape.y > Constants::SCREEN_HEIGHT)
	{
		return true;
	}
	return false;
}
