#pragma once
#include "raylib.h"

#include "Grid.h"
#include "Vector2AStar.h"
#include "InformationDisplay.h"

#include "easings.h"



class Pawn
{
public:
	Pawn();
	Pawn(Vector2 positionP);
	Pawn(Vector2 positionP,float widthP,float heightP);
	~Pawn();

	void Init();
	void Draw();
	void Update();
		
	Vector2AStar position;
	float x;
	float y;

	float width;
	float height;

	void MoveTo(Vector2AStar positionToGo);

	InformationDisplay* GetInformations() { return informations; }

	Grid* gridRef;

private:
	InformationDisplay* informations;

};

