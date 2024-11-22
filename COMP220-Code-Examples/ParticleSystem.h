#pragma once

#include "Particle.h"

class ParticleSystem
{
public:
	const static int numOfParticles = 1000;

	const Particle* const getParticles() { return pParticles; };
	
	ParticleSystem();
	void update();

	~ParticleSystem();
private:
	Particle * pParticles;
};

