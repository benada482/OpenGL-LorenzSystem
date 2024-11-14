#include <iostream>
#include <SDL.h>
#include <gl\glew.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

#include <glm/glm.hpp> //Math libs
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>	//Asset importers
#include <assimp/scene.h>	
#include <assimp/postprocess.h>	

#include "Shader.h" //Shader files
#include "Vertex.h"
#include <random>
#include "main.h"

#include "Window.h";
#include "ParticleSystem.h"

int main(int argc, char** argsv)
{
	srand(time(NULL));

	Window window;
	if (window.init() == false)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Window/SDL Initialisation failed", SDL_GetError(), NULL);
	}

	//Delta time setup
	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 last = 0;
	double deltaTime = 0.0;

	ParticleSystem particleSystem;
	//Event loop, we will loop until running is set to false, usually if escape has been pressed or window is closed
	bool running = true;
	//SDL Event structure, this will be checked in the while loop
	SDL_Event ev;
	while (running)
	{
		//deltaTime calc
		last = now;
		now = SDL_GetPerformanceCounter();
		deltaTime = (double)((now - last) * 1000 / (double)SDL_GetPerformanceFrequency());

		//stored as unsigned char so if value goes about 256 it will overflow to be stored within the 255 range
		unsigned char green = (1 + sin(SDL_GetTicks() * 0.0001)) * 128;
		unsigned char red = (1 + sin(SDL_GetTicks() * 0.0002)) * 128;
		unsigned char blue = (1 + sin(SDL_GetTicks() * 0.0003)) * 128;

		const Particle* const pParticles = particleSystem.getParticles();
		for (int i = 0; i < ParticleSystem::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

		 int x = (particle.xPos + 1) * Window::screenWidth / 2;
		 int y = (particle.yPos + 1) * Window::screenHeight / 2;

		 window.setPixel(x, y, red, green, blue);
		}

		

		/*for (int y = 0; y < Window::screenHeight; y++)
		{
			for (int x = 0; x < Window::screenWidth; x++)
			{
				window.setPixel(x, y, red, green, blue);
			}
		}*/

		//Draws to screen
		window.update();

		//Poll for the events which have happened in this frame
		//https://wiki.libsdl.org/SDL_PollEvent
		//PUT INTO WINDOW.CPP PROCESS FUNCTION ON TUTORIAL
		while (SDL_PollEvent(&ev))
		{

			//Switch case for every message we are intereted in
			switch (ev.type)
			{
				//QUIT Message, usually called when the window has been closed
			case SDL_QUIT:
				running = false;
				break;
				//KEYDOWN Message, called when a key has been pressed down
			case SDL_KEYDOWN:
				//Check the actual key code of the key that has been pressed
				switch (ev.key.keysym.sym)
				{
					//Escape key
				case SDLK_ESCAPE:
					running = false;
					break;
				}
			}

		}
	}
	window.close();
	return 0;
}