#include "Window.h"
#include <gl\glew.h>
#include "string.h"

Window::Window()
{
	SDL_Window* window(nullptr);
	SDL_Renderer* renderer(nullptr);
	SDL_Texture* texture(nullptr);
	Uint32* buffer(nullptr);
}

bool Window::init()
{
	buffer = new Uint32[screenWidth * screenHeight];
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

	//Initialize GLEW
	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Unable to initialise GLEW", (char*)glewGetErrorString(glewError), NULL);
	}


	//Sets up variables for renderer and texture and error catches
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, screenWidth, screenHeight);

	if (renderer == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Renderer creation failed", SDL_GetError(), NULL);
		SDL_Quit();
		return false;
	}
	if (texture == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Texture Creation failed", SDL_GetError(), NULL);
		SDL_Quit();
		return false;
	}

	//Sets the buffer value to amount of pixels within window
	//Uint32* buffer = new Uint32[screenWidth * screenHeight];

	//Sets screen to black first
	//memset(buffer, 0, screenWidth * screenHeight*sizeof(Uint32));

	//Sets the screen pixels to hex colour in pairs of RGBA
	for (int i = 0; i < screenWidth * screenHeight; i++)
	{ 
		buffer[i] = 0x000000FF;
	}

	return true;
}

bool Window::processEvents()
{
	return false;
}

void Window::update()
{
	//Updates screen with pixel values
	SDL_UpdateTexture(texture, NULL, buffer, screenWidth * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

}

void Window::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	if (x < 0 || x >= screenWidth || y < 0 || y >= screenHeight) 
	{ 
		return; 
	}
	Uint32 colour = 0;

	colour += red;
	colour <<= 8;
	colour += green;
	colour <<= 8;
	colour += blue;
	colour <<= 8;
	colour += 0xFF;

	buffer[(y * screenWidth) + x] = colour;
}

void Window::clearScreen()
{
	memset(buffer, 0, screenWidth * screenHeight * sizeof(Uint32));
}

void Window::close()
{
	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
