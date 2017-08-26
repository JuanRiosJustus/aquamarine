#pragma once
#include <SFML\Graphics.hpp>

class ColorScheme
{
public:
	static sf::Color getLightBlue();
	static sf::Color getInterimBlue();
	static sf::Color getVoidBlue();
	static sf::Color getRetroGray();
	static sf::Color getMidGray();
	static sf::Color getMidWhite();

	static sf::Color bubbleColor();
	static sf::Color bodyOfWaterColor();
	static sf::Color sandColor();
	static sf::Color sands(int color);
private:
};