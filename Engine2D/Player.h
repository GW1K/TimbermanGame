#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "LoadObject.h"

class Player : public LoadObject
{
private:
	sf::CircleShape player;
	sf::RenderWindow* window;

public:
	Player(sf::RenderWindow* window);
	void moveRight();
	void moveLeft();
	virtual void draw();
};

