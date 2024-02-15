#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>


/*
	Class that acts as the game engine.
	Wrapper class.
*/


class Game
{
private:
	//Variable
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Game objects
	sf::RectangleShape enemy;

	//Private functions
	void initVariables();
	void initWindow();
	void initEnemies();
public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessore
	const bool running() const;



	//Function
	void pollEvents();
	void updeta();
	void rander();

};

