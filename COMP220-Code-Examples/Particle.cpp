#include "Particle.h"
#include <stdlib.h>
#include <iostream>
#include <random>

//Get random seed from hardware/os. Then use Mersenne Twister to generate further random
static std::random_device rd;
static std::mt19937 gen(rd());
//Clamp the random values from 0.01 to 0.10
static std::uniform_real_distribution<double> dist(0.01, 0.10);

/// <summary>
/// Sets start position of each particle with a randomly generated one from the random function
/// </summary>
Particle::Particle()
{
	xPos = dist(gen);
	yPos = dist(gen);
	zPos = dist(gen);
}

/// <summary>
/// Updates the particles according to the simplified version of the Lorenz Equations. These equations calculate the position in the x, y and z axis. 
/// The x equation is dx/dt = a (y - x)
/// The y equation is dy/dt = b (p - z) - y
/// The z equation is dz/dt = xy - cz
/// 
/// a, b and c are constant variables for the values of sigma, rho and beta. These constants are 10, 28 and 8/3 respectivley.
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