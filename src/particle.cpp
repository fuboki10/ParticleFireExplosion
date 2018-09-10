#include "particle.h"
#include<stdlib.h>
#include<math.h>
#include "screen.h"
using namespace caveofprogramming;
const double pi=3.14159265358979323846;
Particle::Particle(void)
{
	init(); 
}

void Particle::init(){
	m_x = rand()/RAND_MAX;
	m_y = rand()/RAND_MAX;
	m_direction = (2 * pi *rand())/RAND_MAX;
	m_speed = (0.04 * rand())/RAND_MAX;
	m_speed *= m_speed;
}

Particle::~Particle(void)
{
}

void Particle::update(int interval){
	m_direction += interval * 0.0003;
	double x_speed = m_speed * cos(m_direction);
	double y_speed = m_speed * sin(m_direction);
	m_x += x_speed * interval;
	m_y += y_speed * interval;
	if (m_x >= 1 || m_x <= -1 || m_y >= 1 || m_y <= -1)
	{
		init();
	}
	if (rand() < RAND_MAX/100)
	{
		init();
	}

}
