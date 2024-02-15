#pragma once
#include<iostream>
#include<vector>

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

	//mouse position
	sf::Vector2i mousePosWindow;

	//game logic
	int points;
	float enemySpawntimer;
	float enemySpawntimerMax;
	int MaxEnemies;

	//game objects
	std::vector<sf::RectangleShape> enemies;
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
	void spawnEnemy();

	void pollEvents();
	void updateMousePosition();
	void updateEnemies();
	void update();
	void renderEnemies();
	void render();
};

