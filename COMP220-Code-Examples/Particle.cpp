#include "Particle.h"
#include <stdlib.h>
#include <iostream>

Particle::Particle()
{
	xPos = ((double)rand() / RAND_MAX) * 0.09 + 0.01;
	yPos = ((double)rand() / RAND_MAX) * 0.09 + 0.01;
	zPos = ((double)rand() / RAND_MAX) * 0.09 + 0.01;

	x = 0.01;
	y = 0;
	z = 0;
	a = 10;
	b = 28;
	c = 8.0 / 3.0;
	t = 0.01;
	int i;
}

void Particle::update()
{
	double dx = (a * (yPos - xPos)) * t;
	double dy = (xPos * (b - zPos) - yPos) * t;
	double dz = (xPos * yPos - c * zPos) * t;

	xPos += dx;
	yPos += dy;
	zPos += dz;
	
}

void Particle::reset()
{
	xPos = ((double)rand() / RAND_MAX) * 0.09 + 0.01;
	yPos = ((double)rand() / RAND_MAX) * 0.09 + 0.01;
	zPos = ((double)rand() / RAND_MAX) * 0.09 + 0.01;
}

Particle::~Particle()
{
	
}