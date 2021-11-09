#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "GameHeaders/Category.hpp"
class SceneNode;

struct Command
{
	Command();
	std::function<void(SceneNode&, sf::Time)> action;
	unsigned int category;
};

#endif