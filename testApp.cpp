#include <string>
#include "Player.h"
#include "testApp.h"
#include "Ball.h"


//here we declare all the global variables. Number of players, names
int players = -1;
int lives = -1;
const int WIDTH = 600;
const int HEIGHT = 600;
const int PADDLE_LENGTH = 100;
//width of 4 different paddles; we can just update to a wall or something if there are less players
int width[4] = {PADDLE_LENGTH};
//position of each player, because each player only has one axis to move on.
int position[4];
Ball ball;


//we need to define functions here as well
//The startMenu function will set number of players and lives, 
//and anything else we need to set up in a menu before we play the game.
void startMenu(){
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

//needs some work, we need to decide how we are going to handle different ammounts of players
void startGame(int p){
	ofBackground(0,0,0);
	
	ball.initialize(HEIGHT/2,WIDTH/2, .7, 1);
	
	//right meow, it just sets the width of any non-player to the width of the window
		for(p;p<=4;p++){
			width[p-1] = WIDTH;
	}

}

void testApp::setup() {
	startMenu();
	startGame(players);

}


void testApp::update() {

	ball.move();
	
	//right now it only works with walls
	if( ball.getX() > (WIDTH) || ball.getX() < 0){
		ball.bounce(1);
	}
	
	
	if( ball.getY() > (HEIGHT) || ball.getY() < 0){
		ball.bounce(0);
	}


}


void testApp::draw() {


	//still need to draw the paddles


	ofCircle(ball.getX(),ball.getY(),6);

}


void testApp::keyPressed(int key) {

}


void testApp::keyReleased(int key) {

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

