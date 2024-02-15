#include<iostream>

#include"game.h"

int main()
{	
	//init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	//initgame engine
	game Game;
	//gameloop
	while (Game.running())
	{
		

		//update
		Game.update();

		//render
		Game.render(); //clear old frame
		
		//Draw your game
		//window.display();//tell app that window is done drawing

	}

	//end of appication


	return 0;

}