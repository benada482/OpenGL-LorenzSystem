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

#include "imGUI/imgui.h"
#include "imGUI/imgui_impl_sdl.h"
#include "imGUI/imgui_impl_opengl3.h"

/// <summary>
/// The main loop responsible for interacting with the renderer, creates the camera postions within the window, 
/// creates pointers to each class so they can all be rendered properly, connects buffer objects so that rendering is efficient. 
/// Handles simple camera movement so that the user can move around a bit within the scene with the wasd keys.
/// </summary>
/// <param name="argc">Used to process command line arguments</param>
/// <param name="argsv">Used to process command line arguments</param>
/// <returns></returns>
int main(int argc, char** argsv)
{
	//Sets up mvp for the camera view within a 3D space
	glm::mat4 mvp, view, projection;
	glm::vec3 position(0, 0, 75), forward(0, 0, -1), rotation(0), right(1, 0, 0), up(0, 1, 0);
	const glm::vec4 cameraFace(0, 0, -1, 0);
	const float walkspeed = 0.2f, rotSpeed = 0.1f;
	projection = glm::perspective(glm::radians(45.f), 4.0f / 3.0f, 0.1f, 100.0f);

	//Creates a pointer to the window, checks if it has been created
	Window window;
	if (window.init() == false)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Window/SDL Initialisation failed", SDL_GetError(), NULL);
	}

	//Sets a target FPS and amount of time per frame to ensure it does not run too quick
	const int targetFPS = 60; 
	const int frameDelay = 1000 / targetFPS; 
	Uint32 frameStart;
	int frameTime;

	//Sets up call to particleSystem and connects it to the window through a pointer
	ParticleSystem particleSystem;
	window.setParticleSystem(&particleSystem);

	// OpenGL VBO setup
	GLuint particleVBO;
	glGenBuffers(1, &particleVBO);
	glBindBuffer(GL_ARRAY_BUFFER, particleVBO);

	// Allocate memory for the VBO with the number being amount of particles
	const size_t maxParticles = 10000000; // Adjust this to your needs
	glBufferData(GL_ARRAY_BUFFER, maxParticles * sizeof(glm::vec3), nullptr, GL_DYNAMIC_DRAW);

	// Unbind buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Shader setup
	Shader shader("BasicVert.glsl", "BasicFrag.glsl");
	shader.set();

	// Update particle buffer
	const Particle* const pParticles = particleSystem.getParticles();
	int particlesToRender = particleSystem.particles.size();

	//Event loop, we will loop until running is set to false, usually if escape has been pressed or window is closed
	bool running = true;
	//SDL Event structure, this will be checked in the while loop
	SDL_Event ev;
	while (running)
	{
		frameStart = SDL_GetTicks(); // Get the time at the start of the frame

		mvp = projection * view;
		//deltaTime calc
		//last = now;
		//now = SDL_GetPerformanceCounter();
		//deltaTime = (double)((now - last) * 1000 / (double)SDL_GetPerformanceFrequency());

		window.clearScreen();
		particleSystem.update();

		const Particle* const pParticles = particleSystem.getParticles();
		int particlesToRender = particleSystem.particles.size(); //get vector size

		// Set particle size to 5 pixels
		glPointSize(1.0f); 

		// Bind the VBO
		glBindBuffer(GL_ARRAY_BUFFER, particleVBO);

		// Map buffer to CPU memory and copy particle positions
		glm::vec3* buffer = (glm::vec3*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		if (buffer) {
			for (int i = 0; i < particlesToRender; i++) {
				buffer[i] = glm::vec3(pParticles[i].xPos, pParticles[i].yPos, pParticles[i].zPos);
			}
			glUnmapBuffer(GL_ARRAY_BUFFER);
		}

		// Unbind buffer
		glBindBuffer(GL_ARRAY_BUFFER, 0);


		// Enable the shader program
		shader.set();

		// Pass the MVP matrix to the shader
		GLuint mvpLoc = glGetUniformLocation(shader.shaderID, "MVP");
		glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));

		// Bind the VBO
		glBindBuffer(GL_ARRAY_BUFFER, particleVBO);

		// Enable vertex attribute (position)
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

		// Draw particles as points
		glDrawArrays(GL_POINTS, 0, particlesToRender);

		// Disable vertex attribute
		glDisableVertexAttribArray(0);

		// Unbind buffer
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//Draws to screen
		window.update();

		//Poll for the events which have happened in this frame
		//https://wiki.libsdl.org/SDL_PollEvent
		//PUT INTO WINDOW.CPP PROCESS FUNCTION ON TUTORIAL
		while (SDL_PollEvent(&ev))
		{
			//Allow for ImGUI to process events
			ImGui_ImplSDL2_ProcessEvent(&ev);
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
			// Update the camera view matrix and mvp with new value
			view = glm::lookAt(position, position + forward, up);
			mvp = projection * view;

		}
		//Delay the program to ensure that it does not exceed the framerate and run too fast
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	window.close();
	return 0;
}