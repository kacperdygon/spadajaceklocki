#include "Platform.h"
#include "constants.cpp"

Platform::Platform()
{
	shape = { Constants::SCREEN_WIDTH / 2, Constants::SCREEN_HEIGHT - Constants::PLATFORM_HEIGHT * 2, Constants::PLATFORM_WIDTH, Constants::PLATFORM_HEIGHT };
}

void Platform::Update()
{
	int mouseX = GetMousePosition().x;
	if (mouseX + shape.width / 2 < Constants::SCREEN_WIDTH
		&& mouseX - shape.width / 2 > 0) {
		shape.x = GetMousePosition().x - (0.5 * shape.width);
	}
	
}

void Platform::Render()
{
	DrawRectangleRec(shape, color);
}

Rectangle Platform::GetShape()
{
	return shape;
}