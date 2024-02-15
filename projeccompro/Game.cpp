#include "Game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;

}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width =  800;
	this->window = new sf::RenderWindow(this->videoMode, "Love Game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}

void Game::initEnemies()
{
	//this->enemy.setPosition();
	this->enemy.setSize(sf::Vector2f(10.f, 10.f));
	this->enemy.setFillColor(sf::Color::Green);
	this->enemy.setOutlineColor(sf::Color::Black);
	this->enemy.setOutlineThickness(1.f);
}


// Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}


Game::~Game()
{
	delete this->window;
}

//Accessore
const bool Game::running() const
{
	return this->window->isOpen();
}



//Functions

void Game::pollEvents()
	{
		
	
			//Event polling
			while (this->window->pollEvent(this->ev))
			{
				switch (this->ev.type)
				{
				case sf::Event::Closed:
					this->window->close();
					break;
				case sf::Event::KeyPressed:
					if (this->ev.key.code == sf::Keyboard::Escape)
					{
						this->window->close();
					}
					break;
				}
			}
	}

	void Game::updeta()
	{
		this->pollEvents();
	}

	void Game::rander()
		/*
			@return void

		   -clear old frame
		   -render new objects
		   -display frame in window

		   Render the game objects.
		*/
{
		this->window->clear();

		//Draw game objects
		this->window->draw(this->enemy);

		this->window->display();
}

