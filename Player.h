class Player{//there are 4 implementations of the player class, regardless of how many people are playing the game


	int lives;
	int red;
	int green;
	int blue;


public:		void setColor(int,int,int);
			int getlives();
			int getPos(int);
			int getRed();
			int getGreen();
			int getBlue();
};

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

