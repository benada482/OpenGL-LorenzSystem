#pragma once
struct Particle
{
	double xPos;
	double yPos;
	double zPos;

	double xSpeed;
	double ySpeed;
	double zSpeed;

	float x, y, z /*a, b, c, t*/;
	float a = 10;
	float b = 28;
	float c = 8.0 / 3.0;
	float t = 0.01;
	double xt, yt, zt;
	int i;


	Particle();
	void update();
	void reset();
	~Particle();
};

