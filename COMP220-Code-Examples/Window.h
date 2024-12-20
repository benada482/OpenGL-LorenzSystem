#pragma once
#include "SDL.h"
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ParticleSystem.h"

/// <summary>
/// Create variable for the window size and assign values, create an integer for the slider value
/// Set functions for window setup, initialisation, connecting the particle system to the window, updating the window, clearing it and closing.
/// Set up pointers to all other variables needed
/// </summary>
class Window
{
public:
	const static int screenWidth = 800;
	const static int screenHeight = 600;
	int sliderInt;
	int particleMin = 0;
	int particleMax = 3000000;

	Window();
	bool init();
	void setParticleSystem(ParticleSystem* ps);
	void update();
	void clearScreen();
	void close();

	SDL_Window* window;
	ParticleSystem* particleSystem;
	Particle particle;
};

