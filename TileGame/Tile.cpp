#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(int xP, int yP): x{xP}, y{yP}
{
	x = xP;
	y = yP;
	pos.x = xP;
	pos.y = yP;
	traversible = true;
}

Tile::Tile(int xP, int yP, float widthP, float heightP)
{
	x = xP;
	y = yP;
	pos.x = xP;
	pos.y = yP;
	width = widthP;
	height = heightP;
	traversible = true;
}

void Tile::Draw()
{
	Color col = GRAY;
	if (!traversible)
	{
		col = BLACK;
	}
	DrawRectangle(pos.x * width, pos.y * height, width - 4, height - 4, col);
}
