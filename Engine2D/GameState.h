#pragma once
#include "State.h"
#include "Engine.h"
#include "Player.h"
#include "Log.h"

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
	

	EngineData& mEngineData;
	Logger mLogger;
};
