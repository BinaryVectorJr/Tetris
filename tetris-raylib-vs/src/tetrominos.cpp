#include "tetromino-base.hpp"
#include "position.hpp"

class LBlock : public TetrominoBase
{
public: 
	LBlock() 
	{
		tetrominoID = 4;

		// Filling up the map for configurations 0 to 3, based on the 3x3 base grid, for L Block
		tetrominoBaseCells[0] = { Position(0,2), Position(1,0), Position(1,1), Position(1,2) };
		tetrominoBaseCells[1] = { Position(0,1), Position(1,1), Position(2,1), Position(2,2) };
		tetrominoBaseCells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,0) };
		tetrominoBaseCells[3] = { Position(0,0), Position(0,1), Position(1,1), Position(2,1) };
	}
};


class JBlock : public TetrominoBase
{
public:
	JBlock()
	{
		tetrominoID = 1;

		// Filling up the map for configurations 0 to 3, based on the 3x3 base grid, for J Block
		tetrominoBaseCells[0] = { Position(0,0), Position(1,0), Position(1,1), Position(1,2) };
		tetrominoBaseCells[1] = { Position(0,1), Position(0,2), Position(1,1), Position(2,1) };
		tetrominoBaseCells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,2) };
		tetrominoBaseCells[3] = { Position(0,1), Position(1,1), Position(2,0), Position(2,1) };
	}
};

class IBlock : public TetrominoBase
{
public:
	IBlock()
	{
		tetrominoID = 5;

		// Filling up the map for configurations 0 to 3, based on the 4x4 base grid, for I Block
		tetrominoBaseCells[0] = { Position(1,0), Position(1,1), Position(1,2), Position(1,3) };
		tetrominoBaseCells[1] = { Position(0,2), Position(1,2), Position(2,2), Position(3,2) };
		tetrominoBaseCells[2] = { Position(2,0), Position(2,1), Position(2,2), Position(2,3) };
		tetrominoBaseCells[3] = { Position(0,1), Position(1,1), Position(2,1), Position(3,1) };
	}
};

class OBlock : public TetrominoBase
{
public:
	OBlock()
	{
		tetrominoID = 3;

		// Filling up the map for configurations 0 to 3, based on the 3x3 base grid, for O Block
		// All rotations are the same for O Block so we can use one state
		tetrominoBaseCells[0] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		//tetrominoBaseCells[1] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		//tetrominoBaseCells[2] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		//tetrominoBaseCells[3] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
	}
};

class SBlock : public TetrominoBase
{
public:
	SBlock()
	{
		tetrominoID = 6;

		// Filling up the map for configurations 0 to 3, based on the 3x3 base grid, for S Block
		tetrominoBaseCells[0] = { Position(0,1), Position(0,2), Position(1,0), Position(1,1) };
		tetrominoBaseCells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,2) };
		tetrominoBaseCells[2] = { Position(1,1), Position(1,2), Position(2,0), Position(2,1) };
		tetrominoBaseCells[3] = { Position(0,0), Position(1,0), Position(1,1), Position(2,1) };
	}
};

class TBlock : public TetrominoBase
{
public:
	TBlock()
	{
		tetrominoID = 7;

		// Filling up the map for configurations 0 to 3, based on the 3x3 base grid, for T Block
		tetrominoBaseCells[0] = { Position(0,1), Position(1,0), Position(1,1), Position(1,2) };
		tetrominoBaseCells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,1) };
		tetrominoBaseCells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,1) };
		tetrominoBaseCells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,1) };
	}
};

class ZBlock : public TetrominoBase
{
public:
	ZBlock()
	{
		tetrominoID = 2;

		// Filling up the map for configurations 0 to 3, based on the 3x3 base grid, for Z Block
		tetrominoBaseCells[0] = { Position(0,0), Position(0,1), Position(1,1), Position(1,2) };
		tetrominoBaseCells[1] = { Position(0,2), Position(1,1), Position(1,2), Position(2,1) };
		tetrominoBaseCells[2] = { Position(1,0), Position(1,1), Position(2,1), Position(2,2) };
		tetrominoBaseCells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,0) };
	}
};