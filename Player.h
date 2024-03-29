#include <string>
#include <cstdlib>

class Player{//there are 4 implementations of the player class, regardless of how many people are playing the game

private:
	int score;
	int lives;
	int red;
	int green;
	int blue;
	double position;//position on the axis of movement
	int length;//length of paddle


public:		
	
		Player();
			
			void setColor(int,int,int);
			void setLength(int l);
			void setPos(int p);
			void setLives(int l);
			void move(int a, double s);
			void die();
			int getLives();
			int getRed();
			int getGreen();
			int getBlue();
			double getPosition();
			int getLength();
			std::string getLivesAsString();
};



