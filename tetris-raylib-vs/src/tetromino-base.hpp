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

public:
	// Unique ID for each of the rotation state of the tetromino within the 4x4 base grid
	int tetrominoID;
	// Storing the position of each tetromino and linking it to a unique ID
	std::map<int, std::vector<Position>> tetrominoBaseCells;	

	// CTOR
	TetrominoBase();
	// Drawing the tetromino shape inside of the 4x4 base grid
	void DrawTetromino();

};