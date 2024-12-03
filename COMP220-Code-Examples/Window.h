#pragma once
#include "SDL.h"
#include <glm/glm.hpp> //Math libs
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ParticleSystem.h"

class Window
{
public:
	const static int screenWidth = 1920;
	const static int screenHeight = 1080;
	int sliderInt;

	Window();
	bool init();
	void setParticleSystem(ParticleSystem* ps);
	void update();
	void clearScreen();
	void close();

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	Uint32* buffer;
	ParticleSystem* particleSystem;
	Particle particle;
};

