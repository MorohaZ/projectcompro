#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

int main()
{	//window
	sf::RenderWindow window(sf::VideoMode(800,600),"love game",sf::Style::Titlebar|sf::Style::Close);
	sf::Event ev;
	
	//gameloop
	while (window.isOpen())
	{
		//event polling
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				break;
			}
		}

		//update
		

		//render
		window.clear();//clear old frame
		window.display();//tell app that window is done drawing

	}

	//end of appication


	return 0;

}