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


class game
{
private:
	//variables
	//window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//game objects
	sf::RectangleShape enemy;

	//private function
	void initVariables();
	void initWindow();
	void initEnemy();
public:
	//constructors | Destructors
	game();
	virtual ~game();

	//accessor
	const bool running() const;

	//Function
	void pollEvents();
	void update();
	void render();
};

