#include "ParticleSystem.h"

/// <summary>
/// Initialises the vector to be the same size as the amount of particles within the system.
/// </summary>
ParticleSystem::ParticleSystem()
{
	particles.resize(numOfParticles); 
}

/// <summary>
/// Checks to make sure the vector is the same size as the vector, if it is not then resize the vector so that the correct amount of particles are stored and get drawn.
/// Runs the update function for each particle so that they move correctly.
/// </summary>
void ParticleSystem::update()
{
	if (particles.size() != numOfParticles) {
		resizeParticles();
	}

	for (auto& particle : particles)
	{
		particle.update();
	}
}

/// <summary>
/// Adjusts vector size to store all particles
/// </summary>
void ParticleSystem::resizeParticles()
{
	particles.resize(numOfParticles);
}

ParticleSystem::~ParticleSystem()
{
}