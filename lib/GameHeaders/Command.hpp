#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "GameHeaders/SceneNode.hpp"

class SceneNode;

struct Command
{
	Command();
	std::function<void(SceneNode& node, sf::Time dt)> action;
	unsigned int category;
};

#endif