#include "tetromino-base.hpp"

TetrominoBase::TetrominoBase()
{
	tetrominoBaseCellSize = 30; // TODO: make it dynamic
	rotationState = 0;
	tetrominoColors = GetCellColors();
	rowOffset = 0;
	columnOffset = 0;
}

void TetrominoBase::TR_DrawTetromino()
{
	// Retrieves the vector of positions for the current rotation state of tetromino
	std::vector<Position> tetrominoTiles = TR_GetTetrominoCellPositions();

	// Range based for loop
	for (Position item : tetrominoTiles)
	{
		// Create rectangle for each cell in the vector
		// Cellsize + 11 adds an 11 pixel offset (10 for border and 1 for canvas start; calculated statically based on grid position on canvas) to the render, to make the squares more legible - needed because of the 29x29 rectangle being made which starts at (1,1)
		DrawRectangle(item.baseCol * tetrominoBaseCellSize + 11, item.baseRow * tetrominoBaseCellSize + 11, tetrominoBaseCellSize - 1, tetrominoBaseCellSize - 1, tetrominoColors[tetrominoID]);
	}
}

void TetrominoBase::TR_MoveTetromino(int _rowOffset, int _colOffset)
{
	rowOffset += _rowOffset;
	columnOffset += _colOffset;
}

std::vector<Position> TetrominoBase::TR_GetTetrominoCellPositions()
{
	// Get the default cell positions for current cell
	std::vector<Position> currCellPos = tetrominoBaseCells[rotationState];

	// Empty vector to hold the moved tiles
	std::vector<Position> afterOffsetCellPos;

	// Looking throuigh all tiles and then adding the offset to the position using a range based for loop
	for (Position item : currCellPos)
	{
		Position newPos = Position(item.baseRow + rowOffset, item.baseCol + columnOffset);
		afterOffsetCellPos.push_back(newPos);
	}

	return afterOffsetCellPos;
}

void TetrominoBase::TR_RotateTetromino()
{
	rotationState++;

	// If rotation state reaches the maximum, we need to reset it to zero
	// Typically 4 rotation states except for O-Block (1)
	if (rotationState == (int)tetrominoBaseCells.size())
	{
		rotationState = 0;
	}
}

void TetrominoBase::TR_UndoRotateTetromino()
{
	rotationState--;

	// Check if Rotation state is -1 we reset it to  the max value it can get
	if (rotationState == -1)
	{
		rotationState = tetrominoBaseCells.size() - 1;
	}
}
