#include "Ground.h"

Ground::Ground()
{
	sandContent.setFillColor(ColorScheme::sandColor());
	sandContent.setPosition(sf::Vector2f(0, 680));
	sandContent.setOutlineColor(ColorScheme::getMidWhite());
	sandContent.setOutlineThickness(2);
	sandContent.setSize(sf::Vector2f(1280, 250));

	for (unsigned int dot = 0; dot < sandAmount; dot++)
	{
		sands[dot].setRadius((rand() % static_cast<int>(10 + 1)));
		sands[dot].setFillColor(ColorScheme::sands((rand() % static_cast<int>(3))));
		sands[dot].setOutlineColor(sf::Color(207, 207, 207, 255));
		sands[dot].setOutlineThickness(1);
		sands[dot].setOrigin(sands[dot].getRadius(), sands[dot].getRadius());
		sands[dot].setPosition(sf::Vector2f((rand() % static_cast<int>(1280 + 1)), (rand() % static_cast<int>((rand() % static_cast<int>(1) + 30)) + 685)));
	}
}

Ground::~Ground()
{
}

void Ground::drawGround(sf::RenderWindow & window)
{
	window.draw(sandContent);
	for (int index = 0; index < sandAmount; index++)
	{
		window.draw(sands[index]);
	}
	
}
