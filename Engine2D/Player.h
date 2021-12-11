#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "LoadObject.h"
#include "Tree.h"
#include "Logger.h"
class Player : public LoadObject
{
private:
	Logger pLogger;
	sf::CircleShape player;
	sf::RenderWindow* window;
	sf::Texture sPlayerTxt;
	sf::Sprite sSpritePlayer;
	side playerSide;

public:
	Player(sf::RenderWindow* window);
	void moveRight();
	void moveLeft();
	virtual void draw();
	side getPlayerSide() const;
};

