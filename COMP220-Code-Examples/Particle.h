#pragma once
#include <random>

/// <summary>
/// Creates values for each particles. Gives values for their position and sets up the constants needed for the Lorenz equations
/// </summary>
struct Particle
{
	double xPos;
	double yPos;
	double zPos;

	float a = 10;
	float b = 28;
	float c = 8.0 / 3.0;
	float t = 0.01;

	Particle();
	void update();
	~Particle();
};

