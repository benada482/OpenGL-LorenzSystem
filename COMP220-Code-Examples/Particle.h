#pragma once
struct Particle
{
	double xPos;
	double yPos;

	double xSpeed;
	double ySpeed;


	Particle();
	void update();
	~Particle();
};

