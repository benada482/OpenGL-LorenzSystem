#include "Window.h"
#include <gl\glew.h>
#include "string.h"

#include "imGUI/imgui.h"
#include "imGUI/imgui_impl_sdl.h"
#include "imGUI/imgui_impl_opengl3.h"

#include "particle.h"



/// <summary>
/// Create a nullptr to window so the value can be filled later.
/// </summary>
Window::Window()
{
	SDL_Window* window(nullptr);
}

/// <summary>
/// Sets up SDL, GLEW and connects OpenGL to open a window and render to that window
/// Set up ImGUI to create a simple GUI on the window
/// </summary>
/// <returns>Returns true when creation of the window is successful</returns>
bool Window::init()
{
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

	//SDL_SetRelativeMouseMode(SDL_TRUE);
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

	//Setup Imgui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	//Connect to the opengl window render
	ImGui_ImplSDL2_InitForOpenGL(window, glContext);
	ImGui_ImplOpenGL3_Init();

	return true;
}

/// <summary>
/// Sets the particleSystem as ps using a pointer so ImGUI can access it
/// </summary>
/// <param name="ps">Outputs the particle system</param>
void Window::setParticleSystem(ParticleSystem* ps)
{
	particleSystem = ps;
}

/// <summary>
/// Sets up ImGUI value from the tutorial on the GitHub: https://github.com/ocornut/imgui.git
/// Allows for a slider to change the amount of particles rendered
/// </summary>
void Window::update()
{
	//Start ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Lorenz Settings");

	//Slider for particle number
	ImGui::Text("Particle Number");
	ImGui::SliderInt("Int slider", &particleSystem->numOfParticles, 0, 100000);
	ImGui::Text("Value: %d", particleSystem->numOfParticles);

	//ImGui::Text("a value");
	//ImGui::SliderFloat("Float Slider", &particle.a, 0.0f, 20.0f);

	ImGui::End();
	
	//Draw it to screen
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	//Updates screen with pixel values
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
/// Closes all variables and context to free memory
/// </summary>
void Window::close()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
	SDL_DestroyWindow(window);
	SDL_Quit();
}
