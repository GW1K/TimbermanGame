#include "GameMenu.h"
#include "Engine.h"
#include <iostream>

GameMenu::GameMenu(sf::RenderWindow  *window)
{
	
	this->window = window;
	font.loadFromFile("./Assets/fonts/font.ttf");
	this->text[0].setFont(font);
	this->text[0].setString("Play");
	this->text[0].setCharacterSize(28);
	this->text[0].setFillColor(sf::Color::Green);
	this->text[0].setPosition(sf::Vector2f(window->getSize().x/2,window->getSize().y/2));
	this->text[1].setFont(font);
	this->text[1].setString("Exit");
	this->text[1].setCharacterSize(28);
	this->text[1].setFillColor(sf::Color::Blue);
	this->text[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2 + 300));
	this->selectedIndex = 1;


}

GameMenu::~GameMenu()
{

}

void GameMenu::draw() {

	for (int i = 0; i < 2; i++)
	{
		this->window->draw(this->text[1]);
	}
}


void GameMenu::MoveUp() 
{

	if (selectedIndex + 1 < 2)
	{

		this->text[selectedIndex].setFillColor(sf::Color::Green);
		selectedIndex++;
		this->text[selectedIndex].setFillColor(sf::Color::Blue);

	}
	
}



void GameMenu::MoveDown()
{
	
	if (selectedIndex - 1 >= 0)
	{
		this->text[selectedIndex].setFillColor(sf::Color::Green);
		selectedIndex--;
		this->text[selectedIndex].setFillColor(sf::Color::Blue);
	}
	

}




/*void GameMenu::Init()
{


	

	
	/*sf::Event event;

	while (menuWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			menuWindow->close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{

			case sf::Keyboard::Up:
			{


				break;
			}
			case sf::Keyboard::Down: {



				break;
			}

			default: {

				break;
			}
			}
		}
	}


	




}*/




