#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "GameHeaders/StateStack.hpp"
class Application
{
public:
	Application();

private:
	void processInput();
	void update(sf::Time dt);
	void render();
	void registerStates();

private:
	StateStack mStateStack;
};

#endif