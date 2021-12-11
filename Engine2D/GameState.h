#pragma once
#include "State.h"
#include "Engine.h"
#include "Player.h"
#include "Log.h"
#include "Tree.h"

class GameState : public State
{
public:
	GameState(EngineData& engineData);
	~GameState();
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);

private:
	void moveRight();
	void moveLeft();

	sf::Sprite background;
	Player player;
	Log log;
	Tree tree;
	
	int score = 0;

	EngineData& mEngineData;
	Logger mLogger;
};
