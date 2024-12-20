#include "Particle.h"
#include <stdlib.h>
#include <iostream>

/// <summary>
/// Create random starting positions of particles
/// </summary>
Particle::Particle()
{
	xPos = ((double)rand() / RAND_MAX) * 0.09;
	yPos = ((double)rand() / RAND_MAX) * 0.09;
	zPos = ((double)rand() / RAND_MAX) * 0.09;
}

/// <summary>
/// Updates the particles according to the simplified version of the Lorenz Equations. These equations calculate the position in the x, y and z axis. 
/// The x equation is dx/dt = a (y - x)
/// The y equation is dy/dt = b (p - z) - y
/// The z equation is dz/dt = xy - cz
/// 
/// a, b and c are constant variables for the values of sigma, rho and beta. These constants are 10, 28 and 8/3 respectivley.
/// The results of these equations are based off the current position of the particle and the result is added to the position so it moves to the correct postion.
/// </summary>
void Particle::update()
{
	double dx = (a * (yPos - xPos)) * t;
	double dy = (xPos * (b - zPos) - yPos) * t;
	double dz = (xPos * yPos - c * zPos) * t;

	xPos += dx;
	yPos += dy;
	zPos += dz;
	
}

Particle::~Particle()
{
	
}