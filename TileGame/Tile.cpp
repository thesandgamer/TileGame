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
