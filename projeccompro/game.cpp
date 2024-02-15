#include "game.h"


//private function
void game::initVariables()
{
	this->window = nullptr;
	//game logic
	this->points = 0;
	this->enemySpawntimerMax = 1000.f;
	this->enemySpawntimer = this->enemySpawntimerMax;
	this->MaxEnemies = 5;
}

void game::initWindow()
{
	this->videoMode.width  = 800;
	this->videoMode.height = 600;

	this->window = new sf::RenderWindow(this->videoMode, "love game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
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
void game::spawnEnemy()
{
	/*
		@return void

		spawn enemies and sets their colors and positions.
		-Sets a random position.
		-Sets a random colors.
		-Add enemy to the vector.
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);
	this->enemy.setFillColor(sf::Color::Green);

	//spawn enemt
	this->enemies.push_back(this->enemy);
}

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

void game::updateMousePosition()
{
	/*
	@return void

	Update the mouse position:
		- Mouse position relative to window(Victor2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);

}

void game::updateEnemies()
{

	/**
		@return void 

		update the enemy spawn timer and spawn enemy
		when the total amount of enemies is smaller than the maximun
		Moves the enemies downward.
	*/

	//updating the timer for enemy spawning
	if (this->enemies.size() < this->MaxEnemies)
	{

		if (this->enemySpawntimer >= this->enemySpawntimerMax)
		{
			//spaw the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawntimer = 0.f;
		}
		else
		{
			this->enemySpawntimer += 1.f;
		}
	}
}

void game::update()
{
	this->pollEvents();

	this->updateMousePosition();

	this->updateEnemies();

	//updete mouse position
	//relative to the screen
	//std::cout << "mouse position = " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";
	//relative to the widow
	//std::cout << "mouse position = " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";

}

void game::renderEnemies()
{

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
	this->renderEnemies();

	this->window->display();
}
