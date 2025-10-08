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

		// Move the tetromino spawn position to the middle of the screen
		// TODO: Make it dynamic
		TR_MoveTetromino(0, 3);
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
		
		// Move the tetromino spawn position to the middle of the screen
		// TODO: Make it dynamic
		TR_MoveTetromino(0, 3);
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

		// Move the tetromino spawn position to the middle of the screen
		// TODO: Make it dynamic
		// Need to change X offset to -1 since the I block is all on one line and hence a blank row is left on top if not done
		TR_MoveTetromino(-1, 3);
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

		// Move the tetromino spawn position to the middle of the screen
		// TODO: Make it dynamic
		// Need Y offset as 4 since first two columns are always filled, thus the third column makes it look uneven
		TR_MoveTetromino(0, 4);
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

		// Move the tetromino spawn position to the middle of the screen
		// TODO: Make it dynamic
		TR_MoveTetromino(0, 3);
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

		// Move the tetromino spawn position to the middle of the screen
		// TODO: Make it dynamic
		TR_MoveTetromino(0, 3);
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

		// Move the tetromino spawn position to the middle of the screen
		// TODO: Make it dynamic
		TR_MoveTetromino(0, 3);
	}
};