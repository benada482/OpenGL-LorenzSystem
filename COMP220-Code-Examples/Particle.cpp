#include "Particle.h"
#include <stdlib.h>

Particle::Particle()
{
	xPos = ((2.0 * rand()) / RAND_MAX) - 1;
	yPos = ((2.0 * rand()) / RAND_MAX) - 1;
	zPos = ((2.0 * rand()) / RAND_MAX) - 1;

	xSpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	ySpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	zSpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
}

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
	if (zPos < -1.0f || zPos > 1.0f)
	{
		zSpeed = -zSpeed;
	}
}

Particle::~Particle()
{
	
}