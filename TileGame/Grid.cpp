#include "Grid.h"

Grid::Grid(int width, int height, int cellWidth, int cellHeight) : GRID_WITH{ width }, GRID_HEIGHT{ height }, CELL_WIDTH{ cellWidth },CELL_HEIGHT{cellHeight}
{
	
	grid.resize(GRID_WITH);
	for (std::vector<Vector2>& i : grid)
	{
		i.resize(GRID_HEIGHT);
	}
	std::cout << "Grid finish to resize" << std::endl;

	for ( int i = 0; i < grid.size();i++ )
	{
		for ( int j = 0; j < grid[i].size(); j++ )
		{
			Vector2 pos = { i,j };
			grid[i][j] = pos;
		}
	}
}

Grid::Grid() 
{
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
	for (std::vector<Vector2> ligne : grid)
	{
		for (Vector2 value : ligne)
		{
			DrawRectangleLines(value.x* CELL_WIDTH, value.y*CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT,WHITE);

		}
	}

}
