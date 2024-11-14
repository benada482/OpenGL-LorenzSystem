#pragma once
#include "SDL.h"

class Window
{
public:
	const static int screenWidth = 1920;
	const static int screenHeight = 1080;

	Window();
	bool init();
	bool processEvents();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void clearScreen();
	void close();

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	Uint32* buffer;
};

