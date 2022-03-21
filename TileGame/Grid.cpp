#include "Grid.h"

Grid::Grid(int width, int height, int cellWidth, int cellHeight) : GRID_WITH{ width }, GRID_HEIGHT{ height }, CELL_WIDTH{ cellWidth },CELL_HEIGHT{cellHeight}
{
	
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
			DrawRectangleLines(tile.pos.x* CELL_WIDTH, tile.pos.y*CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, WHITE);

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
