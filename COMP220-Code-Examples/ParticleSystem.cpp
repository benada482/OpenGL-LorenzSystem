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
	particles.resize(numOfParticles);  // Resize vector to desired size

	// Initialize new particles if vector size increased (or reset values if needed)
	if (particles.size() > numOfParticles) {
		// Initialize newly added particles if needed (e.g., reset values, positions)
		for (size_t i = 0; i < particles.size(); ++i) {
			// Ensure new particles have proper initial values (e.g., random position, velocity)
			if (i >= numOfParticles) {
				// Example: Reset values for new particles
				particles[i].reset();  // Assuming your Particle class has a reset method
			}
		}
	}
}

ParticleSystem::~ParticleSystem()
{
	//delete [] pParticles;
}