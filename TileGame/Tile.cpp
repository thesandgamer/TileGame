#include "Tile.h"
#include "Grid.h"

Tile::Tile()
{
	refToGrid = nullptr;
}

Tile::Tile(int xP, int yP): x{xP}, y{yP}
{
	x = xP;
	y = yP;
	pos.x = xP;
	pos.y = yP;
	traversible = true;
	refToGrid = nullptr;

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
	refToGrid = nullptr;

}

void Tile::Draw()
{
	Color col = GRAY;
	if (!traversible)
	{
		col = BLACK;
	}
	else if (goal)
	{
		col = PURPLE;
	}
	DrawRectangle(pos.x * width + refToGrid->GetGridPos().x , pos.y * height + refToGrid->GetGridPos().y, width - 4, height - 4, col);
}
