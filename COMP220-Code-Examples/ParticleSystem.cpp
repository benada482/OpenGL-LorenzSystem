#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	pParticles = new Particle[NPARTICLES];
}

void ParticleSystem::update()
{
	for (int i = 0; i < ParticleSystem::NPARTICLES; i++)
	{
		pParticles[i].update();
	}
}

ParticleSystem::~ParticleSystem()
{
	delete [] pParticles;
}