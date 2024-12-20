#include "ParticleSystem.h"
#include <execution>

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
	if (particles.size() != numOfParticles) 
	{
		resizeParticles();
	}

	//multithreading, uses the <execution> include, needs C++17 and above
	std::for_each(std::execution::par, particles.begin(), particles.end(),[](Particle& particle) { particle.update(); });
}

/// <summary>
/// Loops through the particles to update the value within the Lorenz equation to the new value set by the slider
/// </summary>
/// <param name="a">Slider set</param>
void ParticleSystem::AvalueSlider(float a)
{
	int i = 0;
	for (i = 0; i < particles.size(); i++)
	{
		particles[i].a = a;
	}
}

/// <summary>
/// Loops through the particles to update the value within the Lorenz equation to the new value set by the slider
/// </summary>
/// <param name="b">Slider set</param>
void ParticleSystem::BvalueSlider(float b)
{
	int i = 0;
	for (i = 0; i < particles.size(); i++)
	{
		particles[i].b = b;
	}
}

/// <summary>
/// Loops through the particles to update the value within the Lorenz equation to the new value set by the slider
/// </summary>
/// <param name="c">Slider set</param>
void ParticleSystem::CvalueSlider(float c)
{
	int i = 0;
	for (i = 0; i < particles.size(); i++)
	{
		particles[i].c = c;
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