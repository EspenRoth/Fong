#include "player.h"
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

Player::Player(){

	length = 150;
	position = 0;
	score = 0;
}

int Player::getRed(){
	
	return red;

}
int Player::getGreen(){
	
	return green;

}
int Player::getBlue(){
	
	return blue;

}
void Player::setColor(int r, int g, int b){

	red = r;

	green = g;

	blue = b;

}
int Player::getLives(){

	return lives;

}
int Player::getPosition(){

	return position;

}
void Player::setLives(int l){

lives = l;

}
void Player::move(int a,int s){

	position = position + a * s;

}
void Player::setLength(int l){

	length = l;

}
void Player::setPos(int p){

	position = p;

}
int Player::getLength(){

return length;

}
string Player::getLivesAsString(){

	std::string s;
	stringstream out;
	out << lives;
	s = out.str();
	return s;


}

