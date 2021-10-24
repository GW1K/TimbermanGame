#include "Engine.h"



void Engine::initVideoSettings() {
	this->title = "Nazwa";
	this->fullscreen = false;
	this->vSync = true;
	this->frameRateLimit = 120;
	this->resolution.width = 640;
	this->resolution.height = 480;
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
			sf::Style::Titlebar | sf::Style::Close
		);
	}
	this->window->setFramerateLimit(this->frameRateLimit);
}
void Engine::initKeys() {

}
void Engine::run() {
	while (this->window->isOpen()) {
		while (this->window->pollEvent(this->sfEvent)) {
			if (this->sfEvent.type == sf::Event::Closed) {
				this->window->close();
			}
		}
	}
}
Engine::Engine() {
	this->initVideoSettings();
	this->initWindow();
	this->initKeys();
}
Engine::~Engine() {
	delete this->window;
}