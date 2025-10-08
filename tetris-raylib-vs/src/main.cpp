#include <raylib.h>
#include "maingame.hpp"

// Keep track of time when last update of game occurred - GLOBAL variable
double lastUpdateTime = 0;
// Checkk for the passage of an interval
bool EventTriggered(double interval)
{
	// Get the time since the program started in seconds
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		// Interval has passed
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	Color backgroundColor = { 44,44,127,255 }; // Dark blue color as a struct of {R,G,B,A}
	// Creating game window
	InitWindow(600, 1200, "Raylib Tetris");
	// Setting our target FPS for the program (defines how fast the game runs); 60 is industry standard
	// Without setting this number, performance differs from PC to PC as rendering of the game will depend on how fast the CPU can run
	SetTargetFPS(60);

	// Creating the main game object for the session
	MainGame mainGame = MainGame();

	// Standard game loop
	// 1. Event Handling
	// 2. Updation of positions
	// 3. Drawing of objects

	// Checking if ESC key is pressed or the 'X' icon is pressed
	while (WindowShouldClose() == false)
	{
		// Setting up controls to move tetromino
		mainGame.MG_HandleInput();

		// Calling an event every set interval - here its 0.2 seconds
		if (EventTriggered(0.2))
		{
			// Move the block down by one row every interval
			mainGame.MG_MoveTetrominoDown();
		}

		// Creating a blank canvas to draw gameobjects on
		BeginDrawing();

		// Setting the background color by clearing the previous frame's graphics
		ClearBackground(backgroundColor);

		// TODO: Multithread this - start a new game/simulation main object and let thats constructor call current game's grid and tetromino
		mainGame.MG_DrawGame();

		// End the drawing of the canvas
		EndDrawing();
	}

	// Closing the window after the task is over
	CloseWindow();
}