#pragma once
#include "raylib.h"

class Actor
{

public:
	Actor();
	Actor(Vector2 positionP);


	Vector2 position;

	bool isActive;	
};

