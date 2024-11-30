#pragma once

#include "Particle.h"
#include <vector>

class ParticleSystem
{
public:
	int numOfParticles = 1000;

	const Particle* const getParticles() { return particles.data(); };
	std::vector<Particle> particles;
	
	ParticleSystem();
	void update();
	void resizeParticles();

	~ParticleSystem();
};

