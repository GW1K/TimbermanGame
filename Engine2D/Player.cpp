#include "Player.h"
Player::Player()
{
	//Pokazowo ko³o potem bedzie teksturowanie obiektu
	player.setRadius(25);
	player.setFillColor(sf::Color::Magenta);
	player.setPosition(sf::Vector2f(1024/2, 720/1.5));
}
void Player::moveRight() {
	player.setPosition(posX+200, posY);
}
void Player::moveLeft() {
	player.setPosition(posX-200, posY);
}
void Player::draw(sf::RenderWindow& window) {
	this->posX = window.getSize().x / 2;
	this->posY = window.getSize().y / 1.5;
	window.draw(player);
}