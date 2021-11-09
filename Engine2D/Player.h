#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Player
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

