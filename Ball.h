class Ball{
	//the ball class has two integer variables for position, and two integer components for velocity(figured this would be the simplest way)
	double xpos;
	double ypos;
	double xvel;
	double yvel;
	
public://these are the functions that any part of the program can use to change the ball.
	//all the variables above are private.
	//these functions are defined below.
	void initialize(double, double, double, double);
	void move(){
		xpos = xpos+xvel;
		ypos = ypos+yvel;
	}
	void bounce(bool);
	double getX(){return xpos;}
	double getY(){return ypos;}

};

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
