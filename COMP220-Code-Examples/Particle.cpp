#include "Particle.h"
#include <stdlib.h>
#include <iostream>

Particle::Particle()
{
	xPos = 0;
	yPos = 0;
	zPos = 0;

	//xSpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	//ySpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	//zSpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	x = 0.1;
	y = 0;
	z = 0;
	a = 10.0;
	b = 28.0;
	c = 8.0 / 3.0;
	t = 0.01;
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

	//float maxAbs = std::max({ std::abs(x), std::abs(y), std::abs(z) });
	//float scale = 1.0 / maxAbs;

	//double xt = x + t * a * (y - x);
	//double yt = y + t * (x * (b - z) - y);
	//double zt = z + t * (x * y - c * z);
	double dxdt = a * (y - x);
	double dydt = (x * (c - z) - y);
	double dzdt = (x * y - b * z);

	double nx = x + t * dxdt;
	double ny = y + t * dydt;
	double nz = z + t * dzdt;

		//x = xt;
		//y = yt;
		//z = zt;

	xPos += nx;
	yPos += ny;
	zPos += nz;
	

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