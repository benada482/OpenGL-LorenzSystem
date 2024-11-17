#pragma once
struct Particle
{
	double xPos;
	double yPos;
	double zPos;

	double xSpeed;
	double ySpeed;
	double zSpeed;

	float a, b, c, x, y, dt, z;
	Particle();
	void update();
	~Particle();
};

