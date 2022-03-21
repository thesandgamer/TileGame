#pragma once
#include "raylib.h"

#include "Grid.h"
#include "Vector2AStar.h"

#include "easings.h"



class Pawn
{
public:
	Pawn();
	Pawn(Vector2 positionP);
	Pawn(Vector2 positionP,float widthP,float heightP);
	~Pawn();

	void Draw();
	void Update();
		
	Vector2AStar position;
	float x;
	float y;

	float width;
	float height;

	void MoveTo(Vector2AStar positionToGo);


	Grid* gridRef;
};
