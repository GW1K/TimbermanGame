#include "Engine.h"

Engine::Engine()
{
	this->initVideoSettings();
	this->initWindow();
}

void Engine::initVideoSettings()
{
	this->title = "Timberman";
	this->fullscreen = false;
	this->vSync = false;
	this->frameRateLimit = 120;
	this->resolution.width = 1024;
	this->resolution.height = 720;
}

void Engine::initWindow()
{
	this->gameScreen = GameScreens::MENU_SCREEN;
	if (this->fullscreen) {
		this->window = new sf::RenderWindow(
			this->resolution,
			this->title,
			sf::Style::Fullscreen
		);
	}
	else {
		this->window = new sf::RenderWindow(
			this->resolution,
			this->title,
			sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize
		);
	}
	this->window->setFramerateLimit(this->frameRateLimit);
	this->startMenu = new GameMenu(this->window);
}

void Engine::run() {
	Player player(window);
	Background background(window);
	while (this->window->isOpen()) {
		while (this->window->pollEvent(this->sfEvent)) {
			switch (sfEvent.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::Resized:
				printf("Width: %i height: %i\n", sfEvent.size.width, sfEvent.size.height);
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			this->gameScreen = GameScreens::MENU_SCREEN;
		}
		if (this->gameScreen == GameScreens::GAME_SCREEN) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
				player.moveRight();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
				player.moveLeft();
			}
		}
		if (this->gameScreen == GameScreens::MENU_SCREEN) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				startMenu->MoveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				startMenu->MoveDown();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			if (startMenu->selectedIndex == 1)
			{
				this->gameScreen = GameScreens::GAME_SCREEN;

			}
			if (startMenu->selectedIndex == 0)
			{
				this->window->close();
			}
		}

		window->clear();
		background.Draw();
		
		if (this->gameScreen == GameScreens::MENU_SCREEN)
		{
			startMenu->draw();
		}
		if (this->gameScreen == GameScreens::GAME_SCREEN)
		{
			player.draw();
		}
		
		window->display();
	}
}
