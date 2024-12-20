#include "Window.h"
#include <gl\glew.h>
#include "string.h"

/// <summary>
/// Create a nullptr to window so the value can be filled later.
/// </summary>
Window::Window()
{
	SDL_Window* window(nullptr);;
}

/// <summary>
/// Sets up SDL, GLEW and connects OpenGL to open a window and render to that window
/// </summary>
/// <returns>Returns true when creation of the window is successful</returns>
bool Window::init()
{
	//buffer = new Uint32[screenWidth * screenHeight];
	//Initialises the SDL Library, passing in SDL_INIT_VIDEO to only initialise the video subsystems
	//https://wiki.libsdl.org/SDL_Init
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//Display an error message box
		//https://wiki.libsdl.org/SDL_ShowSimpleMessageBox
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_Init failed", SDL_GetError(), NULL);
		return false;
	}

	//Create a window, note we have to free the pointer returned using the DestroyWindow Function
	//https://wiki.libsdl.org/SDL_CreateWindow
	window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	//Checks to see if the window has been created, the pointer will have a value of some kind
	if (window == nullptr)
	{
		//Show error
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_CreateWindow failed", SDL_GetError(), NULL);
		//Close the SDL Library
		//https://wiki.libsdl.org/SDL_Quit
		SDL_Quit();
		return false;
	}

	SDL_SetRelativeMouseMode(SDL_TRUE);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	//Set SDL_GL version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//Initialize GLEW
	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Unable to initialise GLEW", (char*)glewGetErrorString(glewError), NULL);
	}

	// Set OpenGL viewport and clear color
	glViewport(0, 0, screenWidth, screenHeight);
	glEnable(GL_DEPTH_TEST); // Enable depth testing
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background


	return true;
}

/// <summary>
/// Updates screen with particles in new locations
/// </summary>
void Window::update()
{
	SDL_GL_SwapWindow(window);
}

/// <summary>
/// Clears the screen of past drawn content leaving it blank
/// </summary>
void Window::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/// <summary>
/// Destroys all variables and context to free memory
/// </summary>
void Window::close()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
