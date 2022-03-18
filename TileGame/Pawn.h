#pragma once
#include "raylib.h"

#include "Grid.h"

class Pawn
{
public:
	Pawn();
	Pawn(Vector2 positionP);
	Pawn(Vector2 positionP,float widthP,float heightP);
	~Pawn();

	void Draw();
		
	Vector2 position;
	float x;
	float y;

	float width;
	float height;

	void MoveTo(Vector2 positionToGo);
};

