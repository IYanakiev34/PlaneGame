#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameHeaders/Aircraft.hpp"
#include "GameHeaders/Command.hpp"
#include "GameHeaders/CommandQueue.hpp"
#include "GameHeaders/SceneNode.hpp"
class Player
{
public:
	enum Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		ActionCount
	};

public:
	Player();
	void handleEvent(const sf::Event& event, CommandQueue& commands);
	void hanldeRealTimeInput(CommandQueue& commands);
	void assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key getAssignedKey(Action action) const;

private:
	void initializeActions();
	bool isRealTimeAction(Action action);

private:
	std::map<sf::Keyboard::Key, Action> mKeyBindings;
	std::map<Action, Command> mActionBindings;
};
#endif