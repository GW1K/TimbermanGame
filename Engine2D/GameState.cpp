#include "GameState.h"
#include <iostream>

GameState::GameState(EngineData& engineData) :
	mEngineData(engineData), mLogger("../Logger.txt"), player(engineData.window), log(engineData.window), tree(engineData.window)
{
	tree.dissapearAllBranches();
	player.moveRight();
	this->mEngineData.input = true;
}

GameState::~GameState()
{
}

void GameState::init()
{
	this->mEngineData.assetManager.loadTexture("gameBackground", "./Assets/background/test.png");
	this->mEngineData.assetManager.loadSound("gameWoodBreak", "./Assets/sounds/wood_break.ogg", this->mEngineData.soundBuffer);

	this->mEngineData.assetManager.getSound("gameWoodBreak").setVolume(30.0f);

	this->background.setTexture(this->mEngineData.assetManager.getTexture("gameBackground"));
	this->background.setPosition(0, 0);
	this->background.setScale(
		this->mEngineData.window->getSize().x / this->background.getLocalBounds().width,
		this->mEngineData.window->getSize().y / this->background.getLocalBounds().height
	);
}

void GameState::handleInput()
{
	if (this->mEngineData.input)
	{
		player.animationReset();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			this->mEngineData.assetManager.loadSound("mainMenuButtonClick", "./Assets/sounds/menu_click.ogg", this->mEngineData.soundBuffer);
			this->mEngineData.assetManager.getSound("mainMenuButtonClick").setVolume(30.0f);
			this->mEngineData.stateMachine.removeState();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			this->mEngineData.assetManager.getSound("gameWoodBreak").play();
			score++;
			player.moveRight();
			tree.updateBranches(score);
			log.setLeft();
			this->mEngineData.input = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			this->mEngineData.assetManager.getSound("gameWoodBreak").play();
			score++;
			player.moveLeft();
			tree.updateBranches(score);
			log.setRight();
			this->mEngineData.input = false;
		}
	}
	
}

void GameState::update(float dt)
{
	player.animation();
	tree.update(dt);
	log.update(dt);
	if (tree.getNearestBranch() == player.getPlayerSide())
	{
		this->mEngineData.input = false;
		this->tree.dissapearAllBranches();
	}
}

void GameState::draw(float dt)
{
	this->mEngineData.window->draw(this->background);
	this->tree.draw();
	this->log.draw();
	this->player.draw();
}
