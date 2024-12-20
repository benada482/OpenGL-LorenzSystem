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

#include "Vertex.h"
#include <random>
#include "main.h"

#include "Window.h";
#include "ParticleSystem.h"

/// <summary>
/// The main loop responsible for interacting with the renderer, creates the camera postions within the window, 
/// creates pointers to each class so they can all be rendered properly, renders through a for loop running through each particle 
/// Handles simple camera movement so that the user can move around a bit within the scene with the wasd keys.
/// </summary>
/// <param name="argc">Used to process command line arguments</param>
/// <param name="argsv">Used to process command line arguments</param>
/// <returns></returns>
int main(int argc, char** argsv)
{
	//Create projection for camera
	projection = glm::perspective(glm::radians(45.f), 4.0f / 3.0f, 0.1f, 100.0f);

	Window window;
	if (window.init() == false)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Window/SDL Initialisation failed", SDL_GetError(), NULL);
	}

	//Variables for FPS counter
	Uint32 startTime = SDL_GetTicks();
	int frameCount = 0;

	ParticleSystem particleSystem;
	//Event loop, we will loop until running is set to false, usually if escape has been pressed or window is closed
	bool running = true;
	//SDL Event structure, this will be checked in the while loop
	SDL_Event ev;
	while (running)
	{
		window.clearScreen();
		particleSystem.update();

		const Particle* const pParticles = particleSystem.getParticles();

		// Set particle size to 5 pixels
		glPointSize(1.0f); 

		// Setup OpenGL to draw particles
		glBegin(GL_POINTS);
		for (int i = 0; i < ParticleSystem::numOfParticles; i++) {
			const Particle& particle = pParticles[i];

			//mvp transformation
			glm::vec4 position(particle.xPos, particle.yPos, particle.zPos, 1.0f);
			glm::vec4 cameraPos = mvp * position;
			// Convert from clip space to normalized device coordinates (NDC)
			glm::vec3 normalisedPos = glm::vec3(cameraPos) / cameraPos.w;

			// Draw particle in transformed position
			glVertex3f(normalisedPos.x, normalisedPos.y, normalisedPos.z);
		}
		glEnd();

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
			case SDL_MOUSEMOTION:
				rotation.y -= ev.motion.xrel * rotSpeed;
				rotation.x -= ev.motion.yrel * rotSpeed;
				glm::mat4 viewRotate(1.f);
				viewRotate = glm::rotate(viewRotate, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
				viewRotate = glm::rotate(viewRotate, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
				forward = glm::normalize(glm::vec3(viewRotate * cameraFace));
				right = glm::normalize(glm::cross(forward, glm::vec3(0, 1, 0)));
				up = glm::normalize(glm::cross(right, forward));
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
				case SDLK_w:
					position += walkspeed * forward;
					break;
				case SDLK_s:
					position -= walkspeed * forward;
					break;
				case SDLK_d:
					position += walkspeed * right;
					break;
				case SDLK_a:
					position -= walkspeed * right;
					break;
				case SDLK_SPACE:
					position += walkspeed * up;
					break;
				case SDLK_LSHIFT:
					position -= walkspeed * up;
					break;
				}
			}
			// Update the camera view matrix
			view = glm::lookAt(position, position + forward, up);

			// Update MVP
			mvp = projection * view;
		}
		//Logic for counting the FPS and outputs to commandline window.
		frameCount++;
		Uint32 currentTime = SDL_GetTicks();
		if (currentTime - startTime >= 1000) 
		{
			float fps = frameCount / ((currentTime - startTime) / 1000.0f);
			std::cout << fps << "," << std::endl;

			// Reset for the next second
			startTime = currentTime;
			frameCount = 0;
		}
	}
	window.close();
	return 0;
}