#pragma once
struct Particle
{
	double xPos;
	double yPos;
	double zPos;

	double xSpeed;
	double ySpeed;
	double zSpeed;

	double x, y, z, a, b, c, t;
	double xt, yt, zt;
	int i;


	Particle();
	void lorenzEquation();
	void update();
	~Particle();
};

