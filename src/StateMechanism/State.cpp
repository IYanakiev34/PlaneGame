#include "GameHeaders/State.hpp"
#include "GameHeaders/StateStack.hpp"

// Context struct constructor
State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player) :
	window(&window),
	textures(&textures),
	fonts(&fonts),
	player(&player)
{
}

// State constructor
State::State(StateStack& stack, Context context) :
	mStack(&stack),
	mContext(context)
{
}

//State distructor
State::~State()
{
}

// calling push state from the stack pointer
void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}
// calling pop state from stack pointer
void State::requestStackPop()
{
	mStack->popState();
}

// clearing the state from the pointer
void State::requestStateClear()
{
	mStack->clearStates();
}