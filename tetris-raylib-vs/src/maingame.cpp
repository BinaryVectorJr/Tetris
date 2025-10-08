#include "maingame.hpp"
#include <random>

MainGame::MainGame()
{
	mainGameGrid = Grid();
	currentUsableTetrominosList = MG_GetAllTetrominos();
	currentTetromino = MG_GetRandomTetromino();
	nextTetromino = MG_GetRandomTetromino();
}

std::vector<TetrominoBase> MainGame::MG_GetAllTetrominos()
{
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}


TetrominoBase MainGame::MG_GetRandomTetromino()
{
	// Check if vector of usable tetrominos is empty
	if (currentUsableTetrominosList.empty())
	{
		currentUsableTetrominosList = MG_GetAllTetrominos();
	}

	// Each of the 7 tetrominos appears atleast once before repeating the cycle
	int randomIndex = rand() % currentUsableTetrominosList.size();
	TetrominoBase selectedTetromino = currentUsableTetrominosList[randomIndex];

	// Removing the selected tetromino from the usable list vector so that the next time it is called, this is not available
	currentUsableTetrominosList.erase(currentUsableTetrominosList.begin() + randomIndex);

	return selectedTetromino;
}

void MainGame::MG_DrawGame()
{
	mainGameGrid.GR_DrawGrid();
	currentTetromino.TR_DrawTetromino();

}

void MainGame::MG_HandleInput()
{
	// Store value of current key pressed
	int keyPressed = GetKeyPressed();

	// Switch the behavior based on the key pressed
	switch (keyPressed)
	{
		case KEY_LEFT:
			MG_MoveTetrominoLeft();
		break;

		case KEY_RIGHT:
			MG_MoveTetrominoRight();
		break;

		case KEY_DOWN:
			MG_MoveTetrominoDown();
		break;

		case KEY_UP:
			MG_RotateTetromino();
		break;
	}
}

void MainGame::MG_MoveTetrominoLeft()
{
	// Move one column left
	currentTetromino.TR_MoveTetromino(0, -1);

	// Checking after moving if all the tiles of the tetromino base are inside the game window or grid
	if (MG_IsTetrominoOutside())
	{
		// If block moves outside the game window, we move it back in
		currentTetromino.TR_MoveTetromino(0, 1);
	}
}

void MainGame::MG_MoveTetrominoRight()
{
	// Move one column right
	currentTetromino.TR_MoveTetromino(0, 1);

	// Checking after moving if all the tiles of the tetromino base are inside the game window or grid
	if (MG_IsTetrominoOutside())
	{
		// If block moves outside the game window, we move it back in
		currentTetromino.TR_MoveTetromino(0, -1);
	}
}

void MainGame::MG_MoveTetrominoDown()
{
	// Move one row down
	currentTetromino.TR_MoveTetromino(1, 0);

	// Checking after moving if all the tiles of the tetromino base are inside the game window or grid
	if (MG_IsTetrominoOutside())
	{
		// If block moves outside the game window, we move it back in
		currentTetromino.TR_MoveTetromino(-1, 0);
	}
}

bool MainGame::MG_IsTetrominoOutside()
{
	// Getting a list of all cells of the tetromino base
	std::vector<Position> currTetrominoTiles = currentTetromino.TR_GetTetrominoCellPositions();

	// Rnage based for loop to check if any tile of tetromino is outside the grid
	for (Position item : currTetrominoTiles)
	{
		if (mainGameGrid.GR_IsCellOutsideGrid(item.baseRow, item.baseCol))
		{
			return true;
		}
	}
	return false;
}

void MainGame::MG_RotateTetromino()
{
	currentTetromino.TR_RotateTetromino();

	// Check if tetromino is outside the game screen or grid bounds
	if (MG_IsTetrominoOutside())
	{
		currentTetromino.TR_UndoRotateTetromino();
	}
}
