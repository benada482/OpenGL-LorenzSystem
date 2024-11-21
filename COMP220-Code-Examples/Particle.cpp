#include "Particle.h"
#include <stdlib.h>
#include <iostream>

Particle::Particle()
{
	xPos = ((double)rand() / RAND_MAX) * 0.09 + 0.01;
	yPos = ((double)rand() / RAND_MAX) * 0.09 + 0.01;
	zPos = ((double)rand() / RAND_MAX) * 0.09 + 0.01;

	//xSpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	//ySpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	//zSpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	x = 0.01;
	y = 0;
	z = 0;
	a = 10;
	b = 28;
	c = 8.0 / 3.0;
	t = 0.02;
	int i;
}

void Particle::lorenzEquation()
{
	double xt = x + t * a * (y - x);
	double yt = y + t * (x * (b - z) - y);
	double zt = z + t * (x * y - c * z);

	x = xt;
	y = yt;
	z = zt;
}

void Particle::update()
{
	//lorenzEquation();

	double dx = (a * (yPos - xPos)) * t;
	double dy = (xPos * (b - zPos) - yPos) * t;
	double dz = (xPos * yPos - c * zPos) * t;

	xPos += dx;
	yPos += dy;
	zPos += dz;
	//std::cout << "X:" << dx << std::endl;
	//std::cout << "Y:" << dy << std::endl;
	//std::cout << "Z:" << dz << std::endl;

	

	/*if (xPos < -1.0 || xPos >= 1.0)
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
	}*/
}

Particle::~Particle()
{
	
}