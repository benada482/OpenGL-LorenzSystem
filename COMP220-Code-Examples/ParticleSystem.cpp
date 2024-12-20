#include "ParticleSystem.h"

/// <summary>
/// Set the particle variable to be equal to the number of particles within the array
/// </summary>
ParticleSystem::ParticleSystem()
{
	pParticles = new Particle[numOfParticles];
}

/// <summary>
/// Run throught the particles one by one to get their new position from the differential equations in the particle.update
/// </summary>
void ParticleSystem::update()
{
	for (int i = 0; i < ParticleSystem::numOfParticles; i++)
	{
		pParticles[i].update();
	}
}

/// <summary>
/// Deletes the array and particles on close
/// </summary>
ParticleSystem::~ParticleSystem()
{
	delete [] pParticles;
}