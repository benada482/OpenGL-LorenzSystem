#include "ParticleSystem.h"

//Adds particles to the array
ParticleSystem::ParticleSystem()
{
	pParticles = new Particle[numOfParticles];
}

//Loops through each particle in the array and updates the position with the function
void ParticleSystem::update()
{
	for (int i = 0; i < ParticleSystem::numOfParticles; i++)
	{
		pParticles[i].update();
	}
}

//Deletes the array on close
ParticleSystem::~ParticleSystem()
{
	delete [] pParticles;
}