//Create a target value for FPS 
const int FPS = 60;

//how many milliseconds each frame should be displayed for
const int delay = 1000 / FPS;

//Stores the time the current frame starts rendering
Uint32 frameStartTime;

//Sets value for  how long frame takes 
int frameTime;

//Variable for memory size of VBO (should be more than maximum on slider)
const size_t maxParticles = 10000000;