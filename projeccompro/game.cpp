#include "game.h"


//private function
void game::initVariables()
{
	this->window = nullptr;
}

void game::initWindow()
{
	this->videoMode.width  = 800;
	this->videoMode.height = 600;

	this->window = new sf::RenderWindow(this->videoMode, "love game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}

void game::initEnemy()
{
	this->enemy.setPosition(10.f,10.f);
	this->enemy.setSize(sf::Vector2f(100.f,100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Blue);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

//constructors | Destructors
game::game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemy();
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

	//updete mouse position
	//relative to the screen
	//std::cout << "mouse position = " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";
	//relative to the widow
	std::cout << "mouse position = " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";

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
	this->window->draw(this->enemy);

	this->window->display();
}
