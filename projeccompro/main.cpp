#include<iostream>

#include"Game.h"

int main() {
	//Init Game engine
	Game game;
	///Gameloop
	while (game.running())
	{


		//Updete
		game.updeta();

		//Rander
		game.rander();

		

	}

	//end of application

	return 0;
}