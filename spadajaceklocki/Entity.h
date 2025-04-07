#pragma once
#include "raylib.h"



class Entity
{

	
public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual ~Entity() = default;
};

