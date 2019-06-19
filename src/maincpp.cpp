
#include <iostream>
#include <SDL.h>
#include "../header/screen.h"
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "../header/swarm.h"
using namespace std;
using namespace caveofprogramming;
const int h_width=Screen::SCREEN_WIDTH/2;
const int h_height =Screen::SCREEN_HEIGHT/2;
unsigned char alternateColor = 1;
int main(int argc, char *argv[]) {

	srand(time(NULL));
	Screen screen;


	if(screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}
	Swarm swarm;

	while (true) {
		// Update particles
		//draw particles
		int  elapsed =SDL_GetTicks();
		swarm.update(elapsed);
		unsigned char green =(unsigned char)((1+sin(elapsed*0.0001))*128);
		unsigned char red =(unsigned char)((1+cos(elapsed*0.0002))*128);
		unsigned char blue =(unsigned char)((1+sin(elapsed*0.0003))*128);
		
		const Particle*const pParticles=swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle=pParticles[i];

			int x = (particle.m_x + 1) * h_width;
			int y =  particle.m_y  * h_width + h_height;
			if(alternateColor==1){
				screen.setPixel(x, y, red, green, blue);
				alternateColor=2;
			}else if(alternateColor==2){
				screen.setPixel(x, y, green, red, blue);
				alternateColor=3;
			}else if(alternateColor==3){
				screen.setPixel(x, y, blue, red, green);
				alternateColor=4;
			}else if(alternateColor==4){
				screen.setPixel(x, y, green, blue, red);
				alternateColor=1;
			}
		}

		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages/events
		if(screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
