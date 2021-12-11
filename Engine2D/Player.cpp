#include "Player.h"
Player::Player(sf::RenderWindow* window) :LoadObject("./Assets/objects/sprite.png"), pLogger("../Logger.txt")
{
	this->window = window;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	pLogger.log("Loaded player texture: " + path);
	objectSprite.setTextureRect(sf::IntRect(0,0,200,224));
}
void Player::moveRight() {
	objectSprite.setPosition(this->window->getSize().x / 2 + 300, this->window->getSize().y / 2 + 75);
	objectSprite.setScale(sf::Vector2f(-1.1, 1.1));
	playerSide = side::RIGHT;
	anim = Animation::HIT;
}
void Player::moveLeft() {
	objectSprite.setPosition(this->window->getSize().x / 2 - 300, this->window->getSize().y / 2 + 75);
	objectSprite.setScale(sf::Vector2f(1.1, 1.1));
	playerSide = side::LEFT;
	anim = Animation::HIT;
}
void Player::animation()
{
	if (anim == Animation::HIT) {
		objectSprite.setTextureRect(sf::IntRect(200, 0, 200, 224));
	}
	else
	{
		objectSprite.setTextureRect(sf::IntRect(0, 0, 200, 224));
	}
}
void Player::animationReset()
{
	anim = Animation::NONE;
}
void Player::draw() {
	window->draw(objectSprite);
}

side Player::getPlayerSide() const
{
	return playerSide;
}
