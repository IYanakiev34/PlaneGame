#ifndef GAME_OVER_HPP
#define GAME_OVER_HPP

#include "GameHeaders/Container.hpp"
#include "GameHeaders/State.hpp"

class GameOverState : public State
{
public:
	GameOverState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

private:
	sf::Text mGameOverText;
	sf::Time mElapsedTime;
};

#endif