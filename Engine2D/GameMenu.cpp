#include "GameMenu.h"
#include <iostream>

GameMenu::GameMenu(GameMainWindow* window)
{
	this->window = window;
	if (!this->font.loadFromFile("./Assets/fonts/font.ttf"))
	{
		std::cout << "Error: couldn't load font from file" << std::endl;
	}

	this->text[0].setFont(this->font);
	this->text[0].setString("Play");
	this->text[0].setCharacterSize(28);
	this->text[0].setFillColor(sf::Color::Green);
	this->text[0].setPosition(sf::Vector2f(
		(window->getSize().x / 2) - this->text[0].getPosition().x,
		(window->getSize().y / 2) - this->text[0].getPosition().y - 50
	));

	this->text[1].setFont(this->font);
	this->text[1].setString("Exit");
	this->text[1].setCharacterSize(28);
	this->text[1].setFillColor(sf::Color::White);
	this->text[1].setPosition(sf::Vector2f(
		(window->getSize().x / 2) - this->text[1].getPosition().x,
		(window->getSize().y / 2) - this->text[1].getPosition().y + 50
	));
	this->selectedIndex = 1;
}

GameMenu::~GameMenu()
{
}

void GameMenu::draw()
{
	for (int i = 0; i < 2; i++)
	{
		this->window->draw(this->text[i]);
	}
}

void GameMenu::moveUp() 
{
	if (selectedIndex + 1 < 2)
	{
		this->text[selectedIndex].setFillColor(sf::Color::Green);
		selectedIndex++;
		this->text[selectedIndex].setFillColor(sf::Color::White);
	}
}

void GameMenu::moveDown()
{
	if (selectedIndex - 1 >= 0)
	{
		this->text[selectedIndex].setFillColor(sf::Color::Green);
		selectedIndex--;
		this->text[selectedIndex].setFillColor(sf::Color::White);
	}
}

int GameMenu::getSelectedIndex()
{
	return this->selectedIndex;
}
