#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
private:
	int totalRows;
	int totalColumns;
	int cellSize;
	std::vector<Color> tetroColors;

public:
	int gameGrid[20][10];	// Declaring a 2D int array with 20 rows and 20 columns; TODO: Make dynamic

	// Constructor (CTOR)
	Grid();	
	// Create the grid for the first time and set all elements to be 0 (denoting empty)
	void GR_InitializeGameGrid();
	// Testing method; TODO: Make it utility fn.by accepting different types of argument
	void GR_Print();
	// Drawing the grid on the window canvas
	void GR_DrawGrid();
	// Checking if a given cell position is outside the grid
	bool GR_IsCellOutsideGrid(int _row, int _col);
	// Checking if a cell is empty in the grid (for collision purposes)
	bool GR_IsCellEmpty(int _row, int _col);
};