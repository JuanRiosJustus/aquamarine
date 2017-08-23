
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Water.h"
#include "Bubbles.h"
#include "Animal.h"

int main()
{
	sf::Vector2i screenDimensions(1280, 720);
	sf::Vector2i blockDimensions(10, 10);

	// Create a window
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2.0f) - 755.0f, (sf::VideoMode::getDesktopMode().height / 2.0f) - 390.0f);

	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "charcoal", sf::Style::Close);
	window.setPosition(centerWindow);
	window.setFramerateLimit(60.0f);

	sf::Sprite background;
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("assets/retro.jpg"))
	{
		std::cout << "Error, no image found" << std::endl;
	}
	background.setTexture(backgroundTexture);

	// the player
	Water water;

	//the bubbles
	Bubbles bubbleSpawner;

	Animal animal;

	/* MAIN WINDOW LOOP */
	while (window.isOpen())
	{

		sf::Event eventHandler;




		/* MAIN EVENT LOOP*/
		while (window.pollEvent(eventHandler))
		{
			switch (eventHandler.type) 
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (eventHandler.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				break;
			}

			
		}

	

		/* MAIN CONTROL FUNCTIONALITY */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
		{
			std::cout << "Going left with: " << sf::Keyboard::A << std::endl;
			char left = 'a';
			//mainPlayer.movePlayer(left);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
		{
			std::cout << "Going right with: " << sf::Keyboard::D << std::endl;
			char right = 'd';
			//mainPlayer.movePlayer(right);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
		{
			std::cout << "Going up with: " << sf::Keyboard::W << std::endl;
			char up = 'w';
			//mainPlayer.movePlayer(up);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			std::cout << "Going down with: " << sf::Keyboard::S << std::endl;
			char down = 's';
			//mainPlayer.movePlayer(down);
		}
		if (sf::Event::MouseButtonPressed)
		{
			std::cout << "Current mouse location: " << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << std::endl;

			animal.innateBehavior(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));

		}
		
		if (true)
		{

		}

		//std::cout << "Current position: " << mainPlayer.latitude() << "," << mainPlayer.longitude() << std::endl;
		window.clear();
		
		window.draw(background);
		water.drawWater(window);
		bubbleSpawner.generateBubbles(window);
		animal.drawAnimal(window);
		
		window.display();
		
	}
	/* END OF MAIN WINDOW */

	return 0;
}