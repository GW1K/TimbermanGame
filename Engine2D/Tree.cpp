#include "Tree.h"

Tree::Tree(sf::RenderWindow* window) :LoadObject("./Assets/objects/test.png"), pLogger("../Logger.txt")
{
	this->window = window;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2 - 75, -225));
	objectSprite.setScale(sf::Vector2f(0.4, 0.35));
	pLogger.log("Loaded Tree texture: " + path);
	pLogger.log("Loaded Branch texture: ./Assets/objects/liscie.png");

	branch.loadFromFile("./Assets/objects/liscie.png");
	for (int i = 0; i < 6; i++)
	{
		branches[i].setTexture(branch);
		branches[i].setScale(sf::Vector2f(0.4, 0.35));
	}
}
void Tree::draw()
{
	window->draw(objectSprite);
	for (int i = 0; i < 6; i++)
	{
		window->draw(branches[i]);
	}
}
void Tree::updateBranches(int x)
{
	for (int j = 6 - 1; j > 0; j--)
	{
		branchesPosition[j] = branchesPosition[j - 1];
	}
	srand(static_cast<unsigned int>(time(0) + x));
	int r = (rand() % 6);
	switch (r)
	{
	case 0:
		branchesPosition[0] = side::LEFT;
		break;
	case 1:
		branchesPosition[0] = side::RIGHT;
		break;
	default:
		branchesPosition[0] = side::NONE;
		break;
	}
}

void Tree::update(float dt)
{
	for (int i = 0; i < 6; i++)
	{
		float height = i * 98;
		if (branchesPosition[i] == side::LEFT)
		{
			branches[i].setPosition(this->window->getSize().x / 2 - 215, height);
		}
		else if (branchesPosition[i] == side::RIGHT)
		{
			branches[i].setPosition(this->window->getSize().x / 2 + 80, height);
		}
		else
		{
			branches[i].setPosition(3000, height);
		}
	}
}
void Tree::dissapearAllBranches()
{
	for (int i = 1; i < 6; i++)
	{
		branchesPosition[i] = side::NONE;
	}
}

side Tree::getNearestBranch() const
{
	return branchesPosition[5];
}
