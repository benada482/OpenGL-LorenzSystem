#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	particles.resize(numOfParticles); //init vector
}

void ParticleSystem::update()
{
	// Check if we need to resize the vector
	if (particles.size() != numOfParticles) {
		resizeParticles();
	}

	//Update each particles, runs through each one to change position
	for (auto& particle : particles)
	{
		particle.update();
	}
}

//Adjusts vector size to store all particles
void ParticleSystem::resizeParticles()
{
	particles.resize(numOfParticles);  
}

ParticleSystem::~ParticleSystem()
{
}