#pragma once

/// <summary>
/// Creates values for each particles. Gives values for their position and sets up the constants needed for the Lorenz equations
/// </summary>
struct Particle
{
	double xPos;
	double yPos;
	double zPos;

	double x = 0.01;
	double y = 0;
	double z = 0;
	double a = 10;
	double b = 28;
	double c = 8.0 / 3.0;
	double t = 0.01;

	Particle();
	void update();
	~Particle();
};

