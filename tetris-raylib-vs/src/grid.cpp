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

	GR_InitializeGameGrid();
}

void Grid::GR_InitializeGameGrid()
{
	for (int currRow = 0; currRow < totalRows; currRow++)
	{
		for (int currCol = 0; currCol < totalColumns; currCol++)
		{
			gameGrid[currRow][currCol] = 0;
		}
	}
}

void Grid::GR_Print()
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

void Grid::GR_DrawGrid()
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

bool Grid::GR_IsCellOutsideGrid(int _row, int _col)
{
	// Boundary checking based on grid total rows and columns
	if (_row >= 0 && _row < totalRows && _col >= 0 && _col < totalColumns)
	{
		return false;
	}
	return true;
}

bool Grid::GR_IsCellEmpty(int _row, int _col)
{
	if (gameGrid[_row][_col] == 0)
	{
		return true;
	}
	return false;
}

// Multithread crit. section to check row completedness
bool Grid::GR_IsRowComplete(int _row)
{
	for (int _col = 0; _col < totalColumns; _col++)
	{
		if (gameGrid[_row][_col] == 0)
		{
			return false;
		}
	}
	return true;
}

// Multithread crit. section to clear completed rows after checking for row completeness
void Grid::GR_ClearRow(int _row)
{
	for (int _col = 0; _col < totalColumns; _col++)
	{
		// Setting the cleared cell to 0 (empty)
		gameGrid[_row][_col] = 0;
	}
}


// Multithread crit. section. after clearing completed row
void Grid::GR_MoveRowsDown(int _rowToMoveDown, int _numRowsToBeMovedDownBy)
{
	for (int _col = 0; _col < totalColumns; _col++)
	{
		// Setting the old row ID to a new row ID by adding however many rows got cleared
		gameGrid[_rowToMoveDown + _numRowsToBeMovedDownBy][_col] = gameGrid[_rowToMoveDown][_col];
		// Clear the old row (after its moved)
		gameGrid[_rowToMoveDown][_col] = 0;
	}
}

// TODO: Multithread this function call as its own separate thread so that it runs parallel to main thread
int Grid::GR_ClearCompletedRows()
{
	int completed = 0;

	// Iterate through all rows of grid in reverse order, starting at the last row up to the 1st row
	for (int _row = totalRows - 1; _row >= 0; _row--)
	{
		if (GR_IsRowComplete(_row))
		{
			GR_ClearRow(_row);
			completed++;
		}
		// If current row is not full but some rows have already been cleared
		else if (completed > 0)
		{
			GR_MoveRowsDown(_row, completed);
		}
	}
	return completed;
}
