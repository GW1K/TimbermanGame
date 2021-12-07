#include "Player.h"
Player::Player(sf::RenderWindow* window):LoadObject("./Assets/objects/player.png")
{
	this->window = window;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2 - 75, this->window->getSize().y / 2 + 150));
	objectSprite.setScale(sf::Vector2f(0.8, 0.8));
}
void Player::moveRight() {
	objectSprite.setPosition(this->window->getSize().x / 2+100, this->window->getSize().y /2);
}
void Player::moveLeft() {
	objectSprite.setPosition(this->window->getSize().x / 2-100, this->window->getSize().y / 2);
}
void Player::draw() {
	window->draw(objectSprite);
}