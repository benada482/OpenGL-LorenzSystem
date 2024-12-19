#pragma once

#include "Particle.h"

class ParticleSystem
{
public:
	//Amount of particles
	const static int numOfParticles = 400000;

	const Particle* const getParticles() { return pParticles; };
	
	ParticleSystem();
	void update();

	~ParticleSystem();
private:
	Particle * pParticles;
};

