#pragma once
#include "Entity.h"

class Block : public Entity
{

	Rectangle shape;
	Color color;
	float fallSpeed;


public:

	Block(int posX, int posY, float fallSpeed, Color color);
	~Block();

	void Update() override;
	void Render() override;

	Rectangle GetShape();

	bool CheckIfOutOfBounds();
};

