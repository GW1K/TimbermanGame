#include "Engine.h"



void Engine::initVideoSettings() {
	this->title = "Nazwa";
	this->fullscreen = false;
	this->vSync = false;
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
			sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize
		);
	}
	this->window->setFramerateLimit(this->frameRateLimit);
}

void Engine::run() {
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Blue);
	player.setPosition(this->resolution.width/2, this->resolution.height / 2);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			player.move(-5.3f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			player.move(5.3f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.move(0.0f, -0.3f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.move(0.0f, 0.3f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			this->window->close();
		}
		window->clear();
		window->draw(player);
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