#pragma once
#include "State.h"
#include "Engine.h"

class GameOverState : public State
{
public:
	GameOverState(EngineData& engineData, int score);
	~GameOverState();
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);

private:
	void moveUp();
	void moveDown();

	sf::Text scoreLabel;
	sf::Text buttonsText[2];
	sf::Sprite buttons[2];
	sf::Sprite background;

	int selectedIndex;
	int score;

	EngineData& mEngineData;
	Logger mLogger;
};

