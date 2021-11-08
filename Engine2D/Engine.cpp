#include "Engine.h"




void Engine::initVideoSettings() {
	this->title = "Timberman";
	this->fullscreen = false;
	this->vSync = false;
	this->frameRateLimit = 120;
	this->resolution.width = 1024;
	this->resolution.height = 720;
}
void Engine::initWindow() {


	


	//this->startMenu = new GameMenu();

	
	gameScreen = GameScreens::MENU_SCREEN;
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
	startMenu = GameMenu(window);
}

void Engine::run() {
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
			this->window->close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
			player.moveRight();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			player.moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			startMenu.MoveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			startMenu.MoveDown();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			if (startMenu.selectedIndex == 1)
			{
				gameScreen = GameScreens::GAME_SCREEN;

			}
			if (startMenu.selectedIndex == 0)
			{
				this->window->close();

			}

			
		}

		window->clear();
		background.Draw(*window);
		
		if (gameScreen == GameScreens::MENU_SCREEN)
		{
			startMenu.draw();
		}
		if (gameScreen == GameScreens::GAME_SCREEN)
		{
			player.draw(*window);
		}

		
		window->display();
		
		
	}
}



Engine::Engine() {
	this->initVideoSettings();
	this->initWindow();
}
Engine::~Engine() {
	delete this->window;
}