#pragma once
#include <raylib.h>
#include "Grid.h"

enum class CusorState
{
	NOONE,
	PAWN_SELECTED,
	PAWN_SELECTED_MOVE,
	PAWN_SELECTED_CANT_MOVE,
	SELECT,
};

class Cursor
{
public:
	Cursor();
	Cursor(Vector2 positionP);
	~Cursor();

	void Start();
	void Updtate();
	void Draw();

private:
	Vector2 position;

	Vector2 mousePos;
	Vector2 mousePosInGrid;

	Grid* gridRef;

	CusorState state;

};

