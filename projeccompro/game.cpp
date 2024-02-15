#include "game.h"


//private function
void game::intiVariables()
{
	this->window = nullptr;
}

void game::intiWindow()
{
	this->videoMode.width  = 800;
	this->videoMode.height = 600;

	this->window = new sf::RenderWindow(this->videoMode, "love game", sf::Style::Titlebar | sf::Style::Close);
}

//constructors | Destructors
game::game()
{
	this->intiVariables();
	this->intiWindow();
}


game::~game()
{
	delete this->window;
}


//accessor
const bool game::running() const
{
	return this->window->isOpen();
}

//Function
void game::pollEvents()
{
	//event polling
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


void game::update()
{
	this->pollEvents();
}

void game::render()
{
	/*
		@retrun void

		-clear old frame
		-render objects
		-display frame in window

	render the game objects.
	*/
	this->window->clear();

	//draw game objects

	this->window->display();
}
