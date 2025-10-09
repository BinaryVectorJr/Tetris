#include "maingame.hpp"
#include <random>

MainGame::MainGame()
{
	mainGameGrid = Grid();
	currentUsableTetrominosList = MG_GetAllTetrominos();
	currentTetromino = MG_GetRandomTetromino();
	nextTetromino = MG_GetRandomTetromino();
	isGameOver = false;
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

	// Press R to restart if game is over
	if (isGameOver && keyPressed == KEY_R)
	{
		isGameOver = false;
		MG_ResetGame();
	}

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
	// Check if game is over first
	if (!isGameOver)
	{
		// Move one column left
		currentTetromino.TR_MoveTetromino(0, -1);

		// Checking after moving if all the tiles of the tetromino base are inside the game window or grid
		// Fitness check to ensure collision happens if we move from left side
		if (MG_IsTetrominoOutside() || MG_TetrominoFitsInCell() == false)
		{
			// If block moves outside the game window, we move it back in
			currentTetromino.TR_MoveTetromino(0, 1);
		}
	}
}

void MainGame::MG_MoveTetrominoRight()
{
	// Check if game is over first
	if (!isGameOver)
	{
		// Move one column right
		currentTetromino.TR_MoveTetromino(0, 1);

		// Checking after moving if all the tiles of the tetromino base are inside the game window or grid
		// Fitness check to ensure collision ahppens if we move from right side
		if (MG_IsTetrominoOutside() || MG_TetrominoFitsInCell() == false)
		{
			// If block moves outside the game window, we move it back in
			currentTetromino.TR_MoveTetromino(0, -1);
		}
	}
}

void MainGame::MG_MoveTetrominoDown()
{
	// Check if game is over first
	if (!isGameOver)
	{
		// Move one row down
		currentTetromino.TR_MoveTetromino(1, 0);

		// Checking after moving if all the tiles of the tetromino base are inside the game window or grid
		// Also checking if there is empty space for the tetromino to fit - if tetromino encounters a cell that is already occupied, means that there is a tetromino (or a part of it) there, and we can undo the move and lock in place
		if (MG_IsTetrominoOutside() || MG_TetrominoFitsInCell() == false)
		{
			// If block moves outside the game window, we move it back in
			currentTetromino.TR_MoveTetromino(-1, 0);
			MG_LockTetromino();
		}
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
	// Check if game is over first
	if (!isGameOver)
	{
		currentTetromino.TR_RotateTetromino();

		// Check if tetromino is outside the game screen or grid bounds
		// Fitness check to ensure that collision happens when rotating
		if (MG_IsTetrominoOutside() || MG_TetrominoFitsInCell() == false)
		{
			currentTetromino.TR_UndoRotateTetromino();
		}
	}
}

void MainGame::MG_LockTetromino()
{
	// Current tile positions of the tetromino base
	std::vector<Position> currentTetrominoToLock = currentTetromino.TR_GetTetrominoCellPositions();
	// For each cell position we will store the ID of the tetromino into the grid, that way we can signify the tetromino is locked 9and "delete" the current tetromino
	for (Position item : currentTetrominoToLock)
	{
		mainGameGrid.gameGrid[item.baseRow][item.baseCol] = currentTetromino.tetrominoID;
	}
	// Setting the next in line as current
	currentTetromino = nextTetromino;

	// Checking if newly created tetromino fits; if not GAME OVER
	if (MG_TetrominoFitsInCell() == false)
	{
		isGameOver = true;
	}

	// Generate a new next in line
	nextTetromino = MG_GetRandomTetromino();

	// TODO: Multithread this on its own thread
	mainGameGrid.GR_ClearCompletedRows();
}

bool MainGame::MG_TetrominoFitsInCell()
{
	// Check over all the cells of the tetromino base
	std::vector<Position> currentTetrominoToCheckForFitness = currentTetromino.TR_GetTetrominoCellPositions();
	for (Position item : currentTetrominoToCheckForFitness)
	{
		// Check if any cells are occupied in the grid
		if (mainGameGrid.GR_IsCellEmpty(item.baseRow, item.baseCol) == false)
		{
			return false; // The tetromino cannot move into that space as it is already occupied
		}
	}
	return true; // The tetromino can move into that space 
}

void MainGame::MG_ResetGame()
{
	// Clear the grid (set all cells to 0)
	mainGameGrid.GR_InitializeGameGrid();

	//  Get the list of all tetrominos again
	currentUsableTetrominosList = MG_GetAllTetrominos();

	// Select a new random current block and new random next block from the newly populated list
	currentTetromino = MG_GetRandomTetromino();
	nextTetromino = MG_GetRandomTetromino();
}
