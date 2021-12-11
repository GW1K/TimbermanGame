#pragma once
#include "LoadObject.h"
enum class side
{
	LEFT,
	RIGHT,
	NONE
};
class Tree : public LoadObject
{
private:
	sf::RenderWindow* window;
	sf::Texture branch;
	sf::Sprite branches[6];
	side branchesPosition[6];
	Logger pLogger;
public:
	Tree(sf::RenderWindow* window);
	void draw();
	void updateBranches(int x);
	void update(float dt);
	void dissapearAllBranches();
	side getNearestBranch() const;

};

