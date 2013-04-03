#include <string>
#include "Player.h"
#include "testApp.h"
#include "Ball.h"
//here we declare all the global variables. Number of players, window size
int players = -1;
int lives = -1;
const int WIDTH = 600;
const int HEIGHT = 600;
const int PADDLE_LENGTH = 150;
const int PADDLE_WIDTH = 10;
const int PLAYER_SPEED = 1;

bool keyIsDown[256];

//width of 4 different paddles; we can just update to a wall or something if there are less players
int length[4] = {PADDLE_LENGTH,PADDLE_LENGTH,PADDLE_LENGTH,PADDLE_LENGTH};
//position of each player, because each player only has one axis to move on.
int position[4] = {0};
Ball ball;
Player p1;
Player p2;
Player p3;
Player p4;




void startMenu(){//The startMenu function will set number of players and lives, 
//and anything else we need to set up in a menu before we play the game.
	
	
	cout<<"Welcome to Fong, the best game ever!"<<endl;	
	
	while(players < 0 || players > 4){
		cout<<"Enter number of players!(good luck for 4 people on one keyboard)"<<endl;
		cin >> players;
	}

	while (lives < 1 ||lives > 25){
		cout<<"Enter amount of lives, 1-25"<<endl;
		cin >> lives;
	}
}

void startGame(int p){//initializes the game
	ofBackground(0,0,0);
	
	ball.initialize(HEIGHT/2,WIDTH/2, .4, .18);
	
	//first set all the colors to white
	p1.setColor(255,255,255);
	p2.setColor(255,255,255);
	p3.setColor(255,255,255);
	p4.setColor(255,255,255);
	
		//right meow, it just sets the width of any paddle of a non-player to the width of the window
		for(p; p < 4 ;p++){
			length[p] = WIDTH;
		}
		//this next part makes the paddles of players that aren't playing turn black, so they aren't seen.
		if (players < 4){
			p4.setColor(0,0,0);
		}
		if (players < 3){
			p3.setColor(0,0,0);
		}
		if (players < 2){
			p2.setColor(0,0,0);
		}
		if (players < 1){
			p1.setColor(0,0,0);
		}
		
}


void drawPaddles(){//this function just draws the paddles at each of their locations

	//draws the first paddle
	ofSetColor(p1.getRed(),p1.getGreen(),p1.getBlue());
	ofRect(0,position[0],PADDLE_WIDTH,length[0]);

	//seccond
	ofSetColor(p2.getRed(),p2.getGreen(),p2.getBlue());
	ofRect(WIDTH-PADDLE_WIDTH, position[1], PADDLE_WIDTH, length[1]);
	
	//third..
	ofSetColor(p3.getRed(),p3.getGreen(),p3.getBlue());
	ofRect(position[2],0,length[2],PADDLE_WIDTH);

	//fourth
	ofSetColor(p4.getRed(),p4.getGreen(),p4.getBlue());
	ofRect(position[3], HEIGHT - PADDLE_WIDTH, length[3], PADDLE_WIDTH);

}

void changePaddles(){

	//Player 1 controlls
	if (keyIsDown['a']){//down
		position[0] =position[0] + PLAYER_SPEED;
	}
	else if (keyIsDown['q']){//up
		position[0] =position[0] - PLAYER_SPEED;
	}

	//Player 2 controlls
	if (keyIsDown['5']){//down
		position[1] =position[1] + PLAYER_SPEED;
	}
	else if (keyIsDown['8']){//up
		position[1] =position[1] - PLAYER_SPEED;
	}

	//Player 3 controlls
	if (keyIsDown['r']){//right
		position[2] =position[2] + PLAYER_SPEED;
	}
	else if (keyIsDown['e']){//left
		position[2] =position[2] - PLAYER_SPEED;
	}

	//Player 4 controlls
	if (keyIsDown['v']){//right
		position[3] =position[3] + PLAYER_SPEED;
	}
	else if (keyIsDown['c']){//left
		position[3] =position[3] - PLAYER_SPEED;
	}

}

void doesItBounce(){

	if((ball.getX() < 0)   &&   (ball.getY()>position[0]   &&  ball.getY()< position[0]+length[0] )){
		ball.bounce(1);
	}

	//if the ball hits the right paddle, or p2
	if((ball.getX() > WIDTH)   &&   (ball.getY()>position[1]   &&  ball.getY()< position[1]+length[1] )){
		ball.bounce(1);
	}
	
	//if the ball hits the top paddle, or p3
	if((ball.getY() < 0)   &&   (ball.getX()>position[2]   &&  ball.getX()< position[2]+length[2] )){
		ball.bounce(0);
	}
	
	//if the ball hits the bottom paddle, or p4
	if((ball.getY() > HEIGHT)   &&   (ball.getX()>position[3]   &&  ball.getX()< position[3]+length[3] )){
		ball.bounce(0);
	}

}






void testApp::setup() {
	startMenu();
	startGame(players);

}

void testApp::update() {

	//updated the position of paddles
	changePaddles();
	
	//updates position of ball
	ball.move();

	//decides whether or not the ball bounces, and changes the velocity based on which side it hits
	doesItBounce();


}

void testApp::draw() {

	
	drawPaddles();
	
	
	//draw the ball
	ofSetColor(250,0,0);
	ofCircle(ball.getX(),ball.getY(),6);

}


void testApp::keyPressed(int key) {
	/*
	
	*/


	keyIsDown[key] = true;
	
		

}

void testApp::keyReleased(int key) {

	keyIsDown[key] = false;

}


void testApp::mouseMoved(int x, int y) {

}


void testApp::mouseDragged(int x, int y, int button) {

}


void testApp::mousePressed(int x, int y, int button) {

}


void testApp::mouseReleased(int x, int y, int button) {

}


void testApp::windowResized(int w, int h) {

}

