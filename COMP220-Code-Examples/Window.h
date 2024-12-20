#pragma once
#include "SDL.h"
#include <glm/glm.hpp> //Math libs
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/// <summary>
/// Create variable for the window size and assign values
/// Set functions for window setup, initialisation, connecting the particle system to the window, updating the window, clearing it and closing.
/// Set up pointers to all other variables needed
/// </summary>
class Window
{
public:
	const static int screenWidth = 800;
	const static int screenHeight = 600;

	Window();
	bool init();
	void update();
	void clearScreen();
	void close();

	SDL_Window* window;
};

