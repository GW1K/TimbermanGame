#pragma once
#include <SFML/Graphics.hpp>
#include "LoadObject.h"
class Background : public LoadObject
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape bg;
public:
	Background(sf::RenderWindow* window, std::string path);
	void draw();
};

