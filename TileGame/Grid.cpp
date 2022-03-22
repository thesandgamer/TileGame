#include "Grid.h"

Grid::Grid(int width, int height, int cellWidth, int cellHeight) : GRID_WITH{ width }, GRID_HEIGHT{ height }, CELL_WIDTH{ cellWidth },CELL_HEIGHT{cellHeight}
{
	gridPosition = { 0,0 };
	grid.resize(GRID_WITH);
	for (std::vector<Tile>& i : grid)
	{
		i.resize(GRID_HEIGHT);
	}
	std::cout << "Grid finish to resize" << std::endl;

	for ( int i = 0; i < grid.size();i++ )
	{
		for ( int j = 0; j < grid[i].size(); j++ )
		{
			Vector2 pos = { i,j };
			grid[i][j].pos = pos;
			grid[i][j].width = CELL_WIDTH;
			grid[i][j].height = CELL_HEIGHT;
		}
	}
	aStar = AStar(GRID_WITH,GRID_HEIGHT);
}

Grid::Grid() 
{
	GRID_WITH = 0;
	GRID_HEIGHT = 0;
	CELL_WIDTH = 0;
	CELL_HEIGHT = 0;
	gridPosition = { 0,0 };	

	aStar = AStar(GRID_WITH, GRID_HEIGHT);

}

Grid::~Grid()
{
}

void Grid::Start()
{

}

void Grid::Update()
{
}

void Grid::Draw()
{
	for (std::vector<Tile> ligne : grid)
	{
		for (Tile tile : ligne)
		{
			tile.Draw();
			DrawRectangleLines(gridPosition.x + tile.pos.x* CELL_WIDTH, gridPosition.y + tile.pos.y*CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, WHITE);

		}
	}

}

bool Grid::IsInGrid(Vector2 pos)
{
	if (pos.x >= 0 && pos.y >= 0 && pos.x < GRID_WITH && pos.y < GRID_HEIGHT)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Peut peut être être fait en mettant un pointeur et changeant la valeur
Vector2 Grid::PosInGrid(Vector2 pos)
{
	Vector2 newPos;
	newPos.x = (int)pos.x / CELL_WIDTH + gridPosition.x;
	newPos.y = (int)pos.y / CELL_HEIGHT + gridPosition.y;

	return newPos;
}

void Grid::Debug_CleanPathVisibility()
{
	for (int i = 0; i < grid.size() ;i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			grid[i][j].goal = false;
		}
	}
}
