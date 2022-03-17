#pragma once
#include <iostream>
#include "raylib.h"
#include <vector>

class Grid
{
public:
	Grid(int width, int height, int cellWidth,int cellHeight);
	Grid();
	~Grid();

	void Start();
	void Update();
	void Draw();


	int GRID_WITH;
	int GRID_HEIGHT;	
	
	int CELL_WIDTH;
	int CELL_HEIGHT;

	std::vector<std::vector<Vector2>> grid;

	Grid& operator=(const Grid& other)
	{
		this->GRID_WITH = other.GRID_WITH;
		this->GRID_HEIGHT = other.GRID_HEIGHT;
		this->CELL_WIDTH = other.CELL_WIDTH;
		this->CELL_HEIGHT = other.CELL_HEIGHT;
		this->grid = other.grid;
		return* this;
	}
	
};

