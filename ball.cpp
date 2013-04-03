#include "ball.h"


void Ball::initialize(double a, double b, double c,double d){

	xpos = a;
	ypos = b; 
	xvel = c;
	yvel = d;

}

void Ball::bounce(bool is_side){

	if(is_side){
		xvel = -1*xvel;
	} 
	else{
		yvel = -1*yvel;
	}

}



