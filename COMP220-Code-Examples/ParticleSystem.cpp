#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	pParticles = new Particle[NPARTICLES];
}

ParticleSystem::~ParticleSystem()
{
	delete [] pParticles;
}