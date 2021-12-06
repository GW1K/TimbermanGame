#include "Player.h"
Player::Player(sf::RenderWindow* window):LoadObject("./Assets/objects/player.png")
{
	//Pokazowo ko³o potem bedzie teksturowanie obiektu
	this->window = window;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	objectSprite.setPosition(sf::Vector2f(this->window->getSize().x/2+100,this->window->getSize().y/2));
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