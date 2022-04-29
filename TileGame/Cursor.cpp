#include "Cursor.h"
#include "Game.h"

Cursor::Cursor()
{
}

Cursor::Cursor(Vector2 positionP): position{positionP}
{
	state = CusorState::NOONE;
}

Cursor::~Cursor()
{
	state = CusorState::NOONE;
}

void Cursor::Start()
{
	gridRef = Game::instance().GetGrid();
}

void Cursor::Updtate()
{
	mousePos = GetMousePosition();
	mousePosInGrid = gridRef->PosInGrid(mousePos);
	position = mousePos;

}

void Cursor::Draw()
{
	Color col = GREEN;
	float x = mousePosInGrid.x * gridRef->CELL_WIDTH ;
	float y = mousePosInGrid.y * gridRef->CELL_HEIGHT ;

	if (mousePosInGrid.x >= 0 && mousePosInGrid.x <= gridRef->GRID_WITH && mousePosInGrid.y >= 0 && mousePosInGrid.x <= gridRef->GRID_HEIGHT)
	{
		state = CusorState::SELECT;
	}
	if (Game::instance().GetPlayer()->GetControledPawn() != nullptr)
	{
		if (!Game::instance().GetPlayer()->GetControledPawn()->haveDoActions)
		{
			if (mousePosInGrid.x >= 0 && mousePosInGrid.x <= gridRef->GRID_WITH && mousePosInGrid.y >= 0 && mousePosInGrid.x <= gridRef->GRID_HEIGHT)
			{
				state = CusorState::PAWN_SELECTED_MOVE;
			}
			else
			{
				state = CusorState::PAWN_SELECTED_CANT_MOVE;
			}
		}
		else
		{
			state = CusorState::PAWN_SELECTED_CANT_MOVE;
		}


	}

	switch (state)
	{
	case CusorState::NOONE:
		break;
	case CusorState::PAWN_SELECTED:
		break;
	case CusorState::PAWN_SELECTED_MOVE:
		Game::instance().GetPlayer()->GetControledPawn()->DrawVisual(mousePosInGrid,false);
		//DrawTexture(sprite, mousePosInGrid.x * gridRef->CELL_WIDTH + gridRef->GetGridPos().x, positionP.y * gridRef->CELL_HEIGHT + gridRef->GetGridPos().y, color);

		break;
	case CusorState::PAWN_SELECTED_CANT_MOVE:
		break;
	case CusorState::SELECT:
		DrawRectangleLines(x + gridRef->GetGridPos().x, y + gridRef->GetGridPos().y, gridRef->CELL_WIDTH, gridRef->CELL_HEIGHT, col);
		break;
	default:
		break;
	}


	//Draw le curseur
	//DrawRectangle(position.x, position.y, gridRef->CELL_WIDTH /2 , gridRef->CELL_HEIGHT /2, col);


}
