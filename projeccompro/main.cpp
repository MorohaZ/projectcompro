#include<iostream>

#include"Game.h"

int main() {
	Game game;
	
	///Gameloop
	while (game.running)
	{
	

		//Updete

		game.updeta();

		//Rander
		game.rander();

		
	}

	//end of application

	return 0;
}