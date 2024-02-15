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
}


// Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
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
{
		this->window->clear(sf::Color(25 , 25 , 255 , 255));

		//Draw game objects

		this->window->display();
}

