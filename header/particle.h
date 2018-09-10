#pragma once

struct Particle{
	double m_x;
	double m_y;
	double m_direction ;
	double m_speed ;
	
public:
	Particle(void);
	virtual ~Particle(void);
	void init();
	void update(int interval);
};

