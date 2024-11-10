#include "Particle.h"
#include <stdlib.h>

Particle::Particle()
{
	xPos = ((2.0 * rand()) / RAND_MAX) - 1;
	yPos = ((2.0 * rand()) / RAND_MAX) - 1;
}

Particle::~Particle()
{
	
}