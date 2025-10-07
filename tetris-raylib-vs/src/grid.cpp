#include "grid.hpp"
#include <iostream>
#include "colors.hpp"

Grid::Grid()
{
	// TODO: Make total rows dynamic (depend on window height)
	totalRows = 20;
	// TODO: Make total columns dynamic (depend on window width)
	totalColumns = 10;
	cellSize = 30;
	tetroColors = GetCellColors();

	InitializeGameGrid();
}

void Grid::InitializeGameGrid()
{
	for (int currRow = 0; currRow < totalRows; currRow++)
	{
		for (int currCol = 0; currCol < totalColumns; currCol++)
		{
			gameGrid[currRow][currCol] = 0;
		}
	}
}

void Grid::Print()
{
	for (int currRow = 0; currRow < totalRows; currRow++)
	{
		for (int currCol = 0; currCol < totalColumns; currCol++)
		{
			std::cout << gameGrid[currRow][currCol];
		}
		std::cout << std::endl;
	}
}

void Grid::DrawGrid()
{
	for (int currRow = 0; currRow < totalRows; currRow++)
	{
		for (int currCol = 0; currCol < totalColumns; currCol++)
		{
			// Iterate through each cell in the grid and then assign its value to cell value variable
			int cellValue = gameGrid[currRow][currCol];

			// Drawing a rectange (actually a square) with the default empty color (cellValue = 0 initially)
			// Cellsize - 1 removes a pixel, to make the total square size slightly smaller than the actual cell size
			// Cellsize + 1 adds a 1 pixel offset to the render, to make the squares more legible - needed because of the 29x29 rectangle being made which starts at (1,1)
			DrawRectangle(currCol * cellSize+1, currRow * cellSize+1, cellSize-1, cellSize-1, tetroColors[cellValue]);
		}
	}
}
