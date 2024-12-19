#pragma once
#include "SDL.h"

class Window
{
public:
	//Variables set for the screen size. 
	const static int screenWidth = 800;
	const static int screenHeight = 600;

	Window();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void clearScreen();
	void close();

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	Uint32* buffer;
};

