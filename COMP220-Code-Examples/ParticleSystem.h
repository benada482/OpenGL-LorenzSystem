#pragma once

#include "Particle.h"

/// <summary>
/// Set the number of particles that the program starts with. 
/// Using a pointer to the particle class store each particles data inside a vector defined below.
/// Functions for ParticleSystem creation, updating the particles and resizing the vector if the particle number changes
/// </summary>
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

