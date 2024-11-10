#pragma once
#include "SDL.h"

class Window
{
public:
	const static int screenWidth = 960;
	const static int screenHeight = 720;

	Window();
	bool init();
	bool processEvents();
	void close();

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	Uint32* buffer;
};

