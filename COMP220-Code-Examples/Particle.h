#pragma once
#include <random>
struct Particle
{
	double xPos;
	double yPos;
	double zPos;

	float x, y, z;
	float a = 10;
	float b = 28;
	float c = 8.0 / 3.0;
	float t = 0.01;

	Particle();
	void update();
	~Particle();
};

