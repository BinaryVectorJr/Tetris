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
	
	// Method to check if the row is complete
	bool GR_IsRowComplete(int _row);
	// Clear the row, if it is determined as a complete row
	void GR_ClearRow(int _row);
	// Once the completed row is cleared, move the rows above down by the amount of rows cleared
	void GR_MoveRowsDown(int _rowToMoveDown, int _numRowsToBeMovedDownBy);

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
	// Combining checking completed rows, removing completed rows, moving down rows above completed rows intp one function
	int GR_ClearCompletedRows();
};