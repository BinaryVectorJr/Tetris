#include "tetromino-base.hpp"

TetrominoBase::TetrominoBase()
{
	tetrominoBaseCellSize = 30; // TODO: make it dynamic
	rotationState = 0;
	tetrominoColors = GetCellColors();
}

void TetrominoBase::DrawTetromino()
{
	// Retrieves the vector of positions for the current rotation state of tetromino
	std::vector<Position> tetrominoTiles = tetrominoBaseCells[rotationState];

	// Range based for loop
	for (Position item : tetrominoTiles)
	{
		// Create rectangle for each cell in the vector
		DrawRectangle(item.baseCol * tetrominoBaseCellSize + 1, item.baseRow * tetrominoBaseCellSize + 1, tetrominoBaseCellSize - 1, tetrominoBaseCellSize - 1, tetrominoColors[tetrominoID]);
	}
}
