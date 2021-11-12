#include "Engine.h"
#include <iostream>

Engine::Engine()
{
	this->window = new GameMainWindow();
}

Engine::~Engine()
{
	delete this->window;
}

void Engine::run()
{
	Player player(window);
	Background background(window);
	while (this->window->isOpen())
	{
		while (this->window->pollEvent(this->sfEvent))
		{
			switch (sfEvent.type)
			{
				case sf::Event::Closed:
					this->window->close();
					break;

				case sf::Event::Resized:
					printf("Width: %i height: %i\n", sfEvent.size.width, sfEvent.size.height);
					break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			this->window->setCurrentScreen(GameScreens::MENU_SCREEN);
		}
		if (this->window->getCurrentScreen() == GameScreens::GAME_SCREEN)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				player.moveRight();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				player.moveLeft();
			}
		}
		if (this->window->getCurrentScreen() == GameScreens::MENU_SCREEN)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				this->window->getStartMenu()->moveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			{
				this->window->getStartMenu()->moveDown();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			if (this->window->getStartMenu()->getSelectedIndex() == 1)
			{
				this->window->setCurrentScreen(GameScreens::GAME_SCREEN);
			}
			if (this->window->getStartMenu()->getSelectedIndex() == 0)
			{
				this->window->close();
			}
		}

		window->clear();
		background.draw();
		
		if (this->window->getCurrentScreen() == GameScreens::MENU_SCREEN)
		{
			this->window->getStartMenu()->draw();
		}
		if (this->window->getCurrentScreen() == GameScreens::GAME_SCREEN)
		{
			player.draw();
		}
		
		window->display();
	}
}
