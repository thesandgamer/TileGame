#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(int xP, int yP): x{xP}, y{yP}
{
	pos.x = x;
	pos.y = y;
}
