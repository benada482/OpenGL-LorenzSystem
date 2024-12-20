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

//Sets up mvp for the camera view within a 3D space
glm::mat4 mvp, view, projection;
glm::vec3 position(0, 0, 75), forward(0, 0, -1), rotation(0), right(1, 0, 0), up(0, 1, 0);
const glm::vec4 cameraFace(0, 0, -1, 0);
const float walkspeed = 0.2f, rotSpeed = 0.1f;