//Variables for camera
glm::mat4 mvp, view, projection;
glm::vec3 position(0, 0, 75), forward(0, 0, -1), rotation(0), right(1, 0, 0), up(0, 1, 0);
const glm::vec4 cameraFace(0, 0, -1, 0);
const float walkspeed = 0.2f, rotSpeed = 0.1f;
