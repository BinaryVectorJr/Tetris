#include <raylib.h>
#include "maingame.hpp"

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