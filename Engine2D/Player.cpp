#include "Player.h"
Player::Player(sf::RenderWindow* window) :LoadObject("./Assets/objects/steave.png"), pLogger("../Logger.txt")
{
	this->window = window;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	pLogger.log("Loaded player texture: " + path);

}
void Player::moveRight() {
	objectSprite.setPosition(this->window->getSize().x / 2 + 300, this->window->getSize().y / 2 + 75);
	objectSprite.setScale(sf::Vector2f(-1.1, 1.1));
	playerSide = side::RIGHT;

}
void Player::moveLeft() {
	objectSprite.setPosition(this->window->getSize().x / 2 - 300, this->window->getSize().y / 2 + 75);
	objectSprite.setScale(sf::Vector2f(1.1, 1.1));
	playerSide = side::LEFT;
}
void Player::draw() {
	window->draw(objectSprite);
}

side Player::getPlayerSide() const
{
	return playerSide;
}
