#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameHeaders/Command.hpp"
#include "GameHeaders/CommandQueue.hpp"
class Player
{
public:
	Player();
	void handleEvent(const sf::Event& event, CommandQueue& commands);
	void hanldeRealTimeInput(CommandQueue& commands);
};
#endif