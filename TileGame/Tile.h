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

	bool traversible;

	Tile& operator=(const Tile& other)
	{
		this->pos = other.pos;
		this->x = other.x;
		this->y = other.y;
		this->traversible = other.traversible;

		return *this;
	}

};

