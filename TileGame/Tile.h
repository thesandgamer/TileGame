#pragma once
#include "raylib.h"

class Tile
{
public:
	Tile();
	Tile(int xP, int yP);
	~Tile() {};

	Vector2 pos;
	int x;
	int y;

};

