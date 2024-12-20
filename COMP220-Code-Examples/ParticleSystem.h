#pragma once

#include "Particle.h"
#include <vector>

/// <summary>
/// Set the number of particles that the program starts with. 
/// Using a pointer to the particle class store each particles data inside a vector defined below.
/// Functions for ParticleSystem creation, updating the particles and resizing the vector if the particle number changes
/// </summary>
class ParticleSystem
{
public:
	int numOfParticles = 1000000;

	const Particle* const getParticles() { return particles.data(); };
	std::vector<Particle> particles;
	
	ParticleSystem();
	void update();
	void resizeParticles();

	~ParticleSystem();
};

