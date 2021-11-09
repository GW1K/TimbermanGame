#pragma once
#include <SFML/Graphics.hpp>
class Background
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape bg;
public:
	Background(sf::RenderWindow* window);
	virtual void Draw();
};

