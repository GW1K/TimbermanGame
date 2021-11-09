#include "Player.h"
Player::Player(sf::RenderWindow* window)
{
	//Pokazowo ko³o potem bedzie teksturowanie obiektu
	this->window = window;
	player.setRadius(25);
	player.setFillColor(sf::Color::Magenta);
	player.setPosition(sf::Vector2f(this->window->getSize().x/2+100,this->window->getSize().y/2));
}
void Player::moveRight() {
	player.setPosition(this->window->getSize().x / 2+100, this->window->getSize().y /2);
}
void Player::moveLeft() {
	player.setPosition(this->window->getSize().x / 2-100, this->window->getSize().y / 2);
}
void Player::draw() {
	window->draw(player);
}