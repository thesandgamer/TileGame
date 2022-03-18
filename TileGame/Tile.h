#pragma once
#include "raylib.h"

class Tile
{
public:
	Tile();
	Tile(int xP, int yP);
	Tile(int xP, int yP,float widthP,float heightP);
	~Tile() {};

	Vector2 pos;
	int x;
	int y;

	float width;
	float height;

	bool traversible;

	void Draw();

	Tile& operator=(const Tile& other)
	{
		this->pos = other.pos;
		this->x = other.x;
		this->y = other.y;
		this->width = other.width;
		this->height = other.height;
		this->traversible = other.traversible;

		return *this;
	}

};

