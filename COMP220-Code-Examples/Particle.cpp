#include "Particle.h"
#include <stdlib.h>

//Sets a random starting position and speed for each particle in the x and y coordinates
Particle::Particle()
{
	xPos = ((2.0 * rand()) / RAND_MAX) - 1;
	yPos = ((2.0 * rand()) / RAND_MAX) - 1;

	xSpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	ySpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
}

/// <summary>
/// Moves each particle by the speed it has defined. 
/// If the particle reaches the limit of the screen border then the speed value is reversed so it will go the opposite way
/// </summary>
void Particle::update()
{
	xPos += xSpeed;
	yPos += ySpeed;

	if (xPos < -1.0 || xPos >= 1.0)
	{
		xSpeed = -xSpeed;
	}
	if (yPos < -1.0 || yPos >= 1.0)
	{
		ySpeed = -ySpeed;
	}
}

//Destructor
Particle::~Particle()
{
	
}