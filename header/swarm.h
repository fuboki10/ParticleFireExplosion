#pragma once
#include "particle.h"
class Swarm
{
public:
	const static int NPARTICLES=5000;
private:
	Particle *m_pParticles;
	int lastTime;
public:
	Swarm(void);
	virtual ~Swarm(void);
	const Particle *const getParticles(){return m_pParticles;};
	void update(int elapsed);
};

