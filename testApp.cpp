#include <string>
#include <fstream>
#include "Player.h"
#include "testApp.h"
#include "ball.h"

//here we declare all the global variables. Number of players, window size
int players = -1;
int lives = -1;
const int WIDTH = 600;
const int HEIGHT = 600;
const int PADDLE_LENGTH = 150;
const int PADDLE_WIDTH = 10;
const double PLAYER_SPEED = .25;
const string FILENAME = "gamestats.txt";
int totalHits = 0;


//for smoothness and double key pressing action!
bool keyIsDown[256];

Ball ball;

Player p1;
Player p2;
Player p3;
Player p4;


void setAllLives(int l){


	p1.setLives(l);
	p2.setLives(l);
	p3.setLives(l);
	p4.setLives(l);


}
void startMenu(){
//The startMenu function will set number of players and lives, 
//and anything else we need to set up in a menu before we play the game.
	
	
	cout<<"Welcome to Fong, the best game ever!"<<endl;	
	
	while(players < 0 || players > 4){
		cout<<"Enter number of players!(good luck for 4 people on one keyboard)"<<endl;
		cin >> players;
	}

	while (lives < 1 ||lives > 9){
		cout<<"Enter amount of lives, 1-9"<<endl;
		cin >> lives;
		setAllLives(lives);
	}
}
void startRound(){

	ball.initialize(WIDTH/2,WIDTH/2,0,0);


}
void startGame(int p){//initializes the game
	
	
	ofBackground(0,0,0);
	
	
	
	//first set all the colors to white, and set initial positions
	p1.setColor(255,255,255);
	p1.setPos(WIDTH/2);
	p1.setLength(PADDLE_LENGTH);
	
	p2.setColor(255,255,255);
	p2.setPos(WIDTH/2);
	p2.setLength(PADDLE_LENGTH);
	
	p3.setColor(255,255,255);
	p3.setPos(WIDTH/2);
	p3.setLength(PADDLE_LENGTH);
	
	p4.setColor(255,255,255);
	p4.setPos(WIDTH/2);
	p4.setLength(PADDLE_LENGTH);
	
		
	//this next part makes the paddles of players that aren't playing turn black, so they aren't seen.
	//also, it sets them to be the length of the window, and start at position 0, turning them into "invisible walls"
	//still need to make it so they can't move, though
	
	if (players < 4){
		p4.setPos(0);
		p4.setColor(0,0,0);
		p4.setLength(WIDTH);
	}
	if (players < 3){
		p3.setPos(0);
		p3.setColor(0,0,0);
		p3.setLength(WIDTH);
	}
	if (players < 2){
		p2.setPos(0);
		p2.setColor(0,0,0);
		p2.setLength(WIDTH);
	}
	if (players < 1){
		p1.setPos(0);
		p1.setColor(0,0,0);
		p1.setLength(WIDTH);
	}
	
	//finally start the round
	startRound();
		
}
void drawPaddles(){//this function just draws the paddles at each of their locations

	//draws the first paddle
	ofSetColor(p1.getRed(),p1.getGreen(),p1.getBlue());
	ofRect(0,p1.getPosition(),PADDLE_WIDTH,p1.getLength());

	//seccond...
	ofSetColor(p2.getRed(),p2.getGreen(),p2.getBlue());
	ofRect(WIDTH-PADDLE_WIDTH,p2.getPosition(),PADDLE_WIDTH,p2.getLength());
	
	//third..
	ofSetColor(p3.getRed(),p3.getGreen(),p3.getBlue());
	ofRect(p3.getPosition(),0,p3.getLength(),PADDLE_WIDTH);

	//fourth
	ofSetColor(p4.getRed(),p4.getGreen(),p4.getBlue());
	ofRect(p4.getPosition(),WIDTH-PADDLE_WIDTH,p4.getLength(),PADDLE_WIDTH);

}
void drawLives(){

	//draw p1 lives
	ofSetColor(p1.getRed(),p1.getGreen(),p1.getBlue());
	ofDrawBitmapString(p1.getLivesAsString(), 100, 200);

	//player 2... you get the picture
	ofSetColor(p2.getRed(),p2.getGreen(),p2.getBlue());
	ofDrawBitmapString(p2.getLivesAsString(), 500, 200);

	//3
	ofSetColor(p3.getRed(),p3.getGreen(),p3.getBlue());
	ofDrawBitmapString(p3.getLivesAsString(), 200, 100);

	//4
	ofSetColor(p4.getRed(),p4.getGreen(),p4.getBlue());
	ofDrawBitmapString(p4.getLivesAsString(), 200, 500);



}
void changePaddles(){

	//Player 1 controlls         if it's a player                       if it can move within bounds              
	if (keyIsDown['a']  &&     p1.getLength() == PADDLE_LENGTH  &&    p1.getPosition() <= WIDTH - PADDLE_LENGTH ){//down
		p1.move(1, PLAYER_SPEED);
	}
	else if (keyIsDown['q'] && p1.getLength() == PADDLE_LENGTH  && p1.getPosition() >= 0){//up
		p1.move(-1, PLAYER_SPEED);
	}

	//Player 2 controlls
	if (keyIsDown['5'] && p2.getLength() == PADDLE_LENGTH  && p2.getPosition() <= WIDTH - PADDLE_LENGTH){//down
		p2.move(1, PLAYER_SPEED);
	}
	else if (keyIsDown['8'] && p2.getLength() == PADDLE_LENGTH && p2.getPosition() >= 0){//up
		p2.move(-1, PLAYER_SPEED);
	}

	//Player 3 controlls
	if (keyIsDown['r'] && p3.getLength() == PADDLE_LENGTH  && p3.getPosition() <= WIDTH - PADDLE_LENGTH){//right
		p3.move(1, PLAYER_SPEED);
	}
	else if (keyIsDown['e'] && p3.getLength() == PADDLE_LENGTH && p3.getPosition() >= 0) {//left
		p3.move(-1, PLAYER_SPEED);
	}

	//Player 4 controlls
	if (keyIsDown['v'] && p4.getLength() == PADDLE_LENGTH  && p4.getPosition() <= WIDTH - PADDLE_LENGTH){//right
		p4.move(1, PLAYER_SPEED);
	}
	else if (keyIsDown['c'] && p4.getLength() == PADDLE_LENGTH && p4.getPosition() >= 0){//left
		p4.move(-1, PLAYER_SPEED);
	}

}
void doesItBounce(){

	if((ball.getX() < 0)   &&   (ball.getY()>p1.getPosition()   &&  ball.getY()< p1.getPosition()+p1.getLength() )){
		ball.bounce(1);
		totalHits++;
	}

	//if the ball hits the right paddle, or p2
	if((ball.getX() > WIDTH)   &&   (ball.getY()>p2.getPosition()   &&  ball.getY()< p2.getPosition()+p2.getLength() )){
		ball.bounce(1);
		totalHits++;
	}
	
	//if the ball hits the top paddle, or p3
	if((ball.getY() < 0)   &&   (ball.getX()>p3.getPosition()   &&  ball.getX()< p3.getPosition()+p3.getLength() )){
		ball.bounce(0);
		totalHits++;
	}
	
	//if the ball hits the bottom paddle, or p4
	if((ball.getY() > HEIGHT)   &&   (ball.getX()>p4.getPosition()   &&  ball.getX()< p4.getPosition()+p4.getLength() )){
		ball.bounce(0);
		totalHits++;
	}

}
void endGame(){

	ofstream out;
	out.open(FILENAME, ios_base::app);

	if(!out){
		cout<<"probelm with file"<<endl;
	}


	out<<"Players this game: "<<players<<endl;
	out<<"Total Hits: "<<totalHits<<endl;
	out<<"\n"<<endl;

	

}
void doesItDie(){

	if((ball.getX() < 0)   &&   !(ball.getY()>p1.getPosition()   &&  ball.getY()< p1.getPosition()+p1.getLength() )){
		p1.die();
		startRound();
	}

	//if the ball hits the right paddle, or p2
	if((ball.getX() > WIDTH)   &&   !(ball.getY()>p2.getPosition()   &&  ball.getY()< p2.getPosition()+p2.getLength() )){
		p2.die();
		startRound();
	}
	
	//if the ball hits the top paddle, or p3
	if((ball.getY() < 0)   &&   !(ball.getX()>p3.getPosition()   &&  ball.getX()< p3.getPosition()+p3.getLength() )){
		p3.die();
		startRound();
	}
	
	//if the ball hits the bottom paddle, or p4
	if((ball.getY() > HEIGHT)   &&   !(ball.getX()>p4.getPosition()   &&  ball.getX()< p4.getPosition()+p4.getLength() )){
		p4.die();
		startRound();
	}

	if(p1.getLives() == 0 && p2.getLives() == 0 && p3.getLives() == 0 && p4.getLives() == 0){

		endGame();

	}
}



//this is where the program starts
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

	//decides whether someone dies, also checks whether or not to end the game, and implements the endGame function
	doesItDie();



}

void testApp::draw() {

	
	drawPaddles();
	drawLives();
	
	
	//draw the ball
	ofSetColor(250,0,0);
	ofCircle(ball.getX(),ball.getY(),6);

}


void testApp::keyPressed(int key) {
	
	if (key == 'p'){

		
		ball.initialize(WIDTH/2, WIDTH/2, .2, -.15);

	}
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

