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
		window->clear();
		background.Draw(*window);
		player.draw(*window);
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