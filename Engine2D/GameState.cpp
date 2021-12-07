#include "GameState.h"
#include <iostream>

GameState::GameState(EngineData& engineData) :
	mEngineData(engineData), mLogger("../Logger.txt"), player(engineData.window), log(engineData.window)
{
}

GameState::~GameState()
{
}

void GameState::init()
{
	this->mEngineData.assetManager.loadTexture("gameBackground", "./Assets/background/gamebg.png");

	this->background.setTexture(this->mEngineData.assetManager.getTexture("gameBackground"));
	this->background.setPosition(0, 0);
	this->background.setScale(
		this->mEngineData.window->getSize().x / this->background.getLocalBounds().width,
		this->mEngineData.window->getSize().y / this->background.getLocalBounds().height
	);
}

void GameState::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->mEngineData.stateMachine.removeState();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		player.moveRight();
		log.setLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		player.moveLeft();
		log.setRight();
	}
}

void GameState::update(float dt)
{
}

void GameState::draw(float dt)
{
	this->mEngineData.window->clear();

	this->mEngineData.window->draw(this->background);
	this->log.update(dt);
	this->log.draw();
	this->player.draw();

	this->mEngineData.window->display();
}
