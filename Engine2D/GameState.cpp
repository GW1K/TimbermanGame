#include "GameState.h"
#include "GameOverState.h"
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
	this->scoreLabel.setFont(this->mEngineData.assetManager.getFont("mainMenuFont"));
	this->scoreLabel.setString("Your score: 0");
	this->scoreLabel.setCharacterSize(40);
	this->scoreLabel.setPosition(sf::Vector2f(
		mEngineData.window->getSize().x / 2.0f - this->scoreLabel.getLocalBounds().width / 2.0f,
		mEngineData.window->getSize().y - 150.0f
	));
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
		this->mEngineData.assetManager.loadSound("playerHit", "./Assets/sounds/player_hit.ogg", this->mEngineData.soundBuffer);
		this->mEngineData.assetManager.getSound("playerHit").play();
		this->mEngineData.input = false;
		this->tree.dissapearAllBranches();
		sf::sleep(sf::milliseconds(250));
		this->mEngineData.stateMachine.addState((State*) new GameOverState(mEngineData, score), true);
		this->mEngineData.assetManager.loadSound("mainMenuButtonClick", "./Assets/sounds/menu_click.ogg", this->mEngineData.soundBuffer);
		this->mEngineData.assetManager.getSound("mainMenuButtonClick").setVolume(30.0f);
	}
	else {
		this->scoreLabel.setString("Your score: " + std::to_string(score));
	}
}

void GameState::draw(float dt)
{
	this->mEngineData.window->draw(this->background);
	this->tree.draw();
	this->log.draw();
	this->player.draw();
	this->mEngineData.window->draw(this->scoreLabel);
}
