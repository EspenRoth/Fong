class Player{//this is actually just one class that has all the data about all four players,
				//because I don't konw how to dynamically instaciate classes.


	int lives;
	
	bool horz;//to tell whether it is tall or short
	
public: void initialize(int);
			int getlives();
			bool is_Horz(int);
			int getPos(int);
};


void initialize(int p){

	

}


bool Player::is_Horz(int i){
	if (i==3||i==4){
		return true;
	}
}





