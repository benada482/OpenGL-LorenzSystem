#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	pParticles = new Particle[numOfParticles];
}

void ParticleSystem::update()
{
	for (int i = 0; i < ParticleSystem::numOfParticles; i++)
	{
		pParticles[i].update();
	}
}

ParticleSystem::~ParticleSystem()
{
	delete [] pParticles;
}