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
	for (std::vector<Tile> ligne : grid)
	{
		for (Tile tile : ligne)
		{
			Color col = GRAY;
			if (!tile.traversible)
			{
				col = BLACK;
			}
			DrawRectangle(tile.pos.x * CELL_WIDTH, tile.pos.y * CELL_HEIGHT, CELL_WIDTH-4, CELL_HEIGHT - 4, col);
			DrawRectangleLines(tile.pos.x* CELL_WIDTH, tile.pos.y*CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, WHITE);

		}
	}

}
