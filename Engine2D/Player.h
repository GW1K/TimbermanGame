#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Player
{
private:
	int posX, posY;
	sf::CircleShape player;

public:
	Player();
	void moveRight();
	void moveLeft();

	virtual void draw(sf::RenderWindow& window);
};

