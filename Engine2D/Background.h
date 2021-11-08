#pragma once
#include <SFML/Graphics.hpp>
class Background
{
private:
	sf::RectangleShape bg;
public:
	Background();
	virtual void Draw(sf::RenderWindow& window);
};

