#pragma once
#include "Entity.h"
class Platform : public Entity
{

private:

	Rectangle shape;
	Color color = { 0, 0, 255, 255 };

public:

	Platform();
	void Update() override;
	void Render() override;

	Rectangle GetShape();
};

