#pragma once
#include "State.h"
#include "Engine.h"

class MainMenuState : public State
{
public:
	MainMenuState(EngineData& engineData);
	~MainMenuState();
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);

private:
	void moveUp();
	void moveDown();

	sf::Text text[2];
	sf::Sprite background;
	int selectedIndex;

	EngineData& mEngineData;
	Logger mLogger;
};
