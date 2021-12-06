#pragma once
#include <stack>
#include "State.h"

class StateMachine
{
public:
	StateMachine() { }
	~StateMachine() { }

	void addState(State* newState, bool isReplacing = true);
	void removeState();
	void processStateChanges();
	State& getCurrentState();

private:
	std::stack<State*> states;
	State* newState = NULL;

	bool isAdding = false;
	bool isReplacing = false;
	bool isRemoving = false;
};
