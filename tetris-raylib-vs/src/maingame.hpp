#pragma once
#include "grid.hpp"
#include "tetrominos.cpp"

class MainGame
{
private:
	// Attribute to hold current tetromino visible on screen - initially it will be a random tetromino
	std::vector<TetrominoBase> currentUsableTetrominosList;
	// Tracking current and next block
	TetrominoBase currentTetromino;
	TetrominoBase nextTetromino;

	// Checking if a block is outside current game session's generated grid (using Grid's checker function)
	bool MG_IsTetrominoOutside();
	// Tetromino rotation - encapsulating into a single method to facilitate reusability
	void MG_RotateTetromino();
	// Lock the tetromino once it reaches the end of the screen, bottom most row
	void MG_LockTetromino();
	// Check every cell of the tetromino to see if it is over an empty cell or not
	bool MG_TetrominoFitsInCell();
	// Reset the game to restart it
	void MG_ResetGame();
	// Method to calculate score
	void MG_UpdateScore(int _linesCleared, int _moveDownPoints);

public: 
	// Creating the main grid for the game session
	Grid mainGameGrid;
	// To check if game is over or still running
	bool isGameOver;

	MainGame();
	// Drawing the gameobjects via the current game session object
	void MG_DrawGame();
	// Handles movement for tetromino on grid for current game session object
	void MG_HandleInput();
	
	// Tetromino movement - encapsulating into different methods to facilitate reusability
	void MG_MoveTetrominoLeft();
	void MG_MoveTetrominoRight();
	void MG_MoveTetrominoDown();

	// Return a random tetromino from usable tetrominos list
	TetrominoBase MG_GetRandomTetromino();
	// Return a vector of all tetrominos
	std::vector<TetrominoBase> MG_GetAllTetrominos();

	// Hold the score of the game
	int gameScore;

};