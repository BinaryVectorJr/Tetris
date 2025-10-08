#pragma once
#include <vector>
#include <map>
#include "position.hpp"
#include "colors.hpp"

class TetrominoBase
{
private:
	int tetrominoBaseCellSize;
	int rotationState;
	std::vector<Color> tetrominoColors;
	int rowOffset;
	int columnOffset;

public:
	// Unique ID for each of the rotation state of the tetromino within the 4x4 base grid
	int tetrominoID;
	// Storing the position of each tetromino and linking it to a unique ID
	std::map<int, std::vector<Position>> tetrominoBaseCells;

	// CTOR
	TetrominoBase();
	// Drawing the tetromino shape inside of the 4x4 base grid
	void TR_DrawTetromino();
	// Moving the block
	void TR_MoveTetromino(int _rowOffset, int _colOffset);
	// Return the position of the cells after applying offset
	std::vector<Position> TR_GetTetrominoCellPositions();
	// Rotating the tetromino
	void TR_RotateTetromino();
	// In case rotation is invalid where the tetromino goes out of bounds of grid or screen
	void TR_UndoRotateTetromino();

};