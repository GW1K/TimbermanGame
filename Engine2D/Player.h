#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "LoadObject.h"
#include "Tree.h"
#include "Logger.h"
enum class Animation{NONE,HIT};
class Player : public LoadObject
{
private:
	Logger pLogger;
	sf::CircleShape player;
	sf::RenderWindow* window;
	sf::Texture sPlayerTxt;
	sf::Sprite sSpritePlayer;
	side playerSide;
	Animation anim = Animation::NONE;
public:
	Player(sf::RenderWindow* window);
	void moveRight();
	void moveLeft();
	void animation();
	void animationReset();
	virtual void draw();
	side getPlayerSide() const;
	sf::Sprite getPlayerSprite();
};

