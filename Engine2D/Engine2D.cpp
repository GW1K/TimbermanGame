#include "Engine.h"

int main()
{
    Engine &gameEngine = Engine::getInstance();
    gameEngine.run();
    return 0;
}
