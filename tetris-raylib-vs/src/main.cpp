#include <raylib.h>
#include "maingame.hpp"
#include "colors.hpp"
#include <iostream>

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
	// Creating game window
	InitWindow(500, 620, "Raylib Tetris");
	// Setting our target FPS for the program (defines how fast the game runs); 60 is industry standard
	// Without setting this number, performance differs from PC to PC as rendering of the game will depend on how fast the CPU can run
	SetTargetFPS(60);

	// Loading in fonts for basic UI - loads into the GPU memory
	Font mainFont = LoadFontEx("font/game_over.ttf", 64, 0, 0);

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

		// Setting the background color by clearing the previous frame's graphics - color defined in colors.hpp
		ClearBackground(darkBlue);

		// TODO: Hardcoded position but change to make dynamic
		// TODO: Multithread to put all UI in its own thread
		// Drawing the UI - Score title
		DrawTextEx(mainFont, "Score", { 365, 15 }, 38, 2, WHITE);
		// Drawing the UI - Rounded rectangle to use as background for the score number
		// x = 320, y = 65, width = 170, height = 60
		DrawRectangleRounded({ 320, 65, 170, 60 }, 0.3, 6, lightBlue);

		// Character array to store text and display it
		char scoreText[10];
		sprintf_s(scoreText, "%d", mainGame.gameScore);
		// Measure the text in terms of width and height (x,y) in pixels
		Vector2 scoreTextSize = MeasureTextEx(mainFont, scoreText, 38, 2);
		// Using the width, we calculate the position of the score text to be centered in the rectangle (dimensions we are using are (x,width) = (320, 170))
		// Drawing the UI - actual score number
		// The calculation is take width of rectangle, then width of text, and subtract. Then the leftover divide into two equal halves and put one half on left of text and other on right of text to keep it centered
		DrawTextEx(mainFont, scoreText, { 320 + (170 - scoreTextSize.x)/2, 70}, 38, 2, WHITE);


		// Drawing the UI - Next tetromino title
		DrawTextEx(mainFont, "Next", { 370, 185 }, 38, 2, WHITE);
		// Drawing the UI - Next tetromino display
		DrawRectangleRounded({ 320, 235, 170, 180 }, 0.3, 6, lightBlue);
		// Drawing the UI - Game Over title only if game is actually over
		if (mainGame.isGameOver)
		{
			DrawTextEx(mainFont, "GAME OVER!", { 318, 460 }, 38, 2, WHITE);
		}

		// TODO: Multithread this - start a new game/simulation main object and let thats constructor call current game's grid and tetromino
		mainGame.MG_DrawGame();

		// End the drawing of the canvas
		EndDrawing();
	}

	// Closing the window after the task is over
	CloseWindow();
}