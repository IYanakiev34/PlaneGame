#include "GameHeaders/Entity.hpp"

void Entity::setVelocity(sf::Vector2f velocity)
{
	_velocity = velocity;
}

void Entity::setVelocity(float x, float y)
{
	_velocity.x = x;
	_velocity.y = y;
}

sf::Vector2f Entity::getVelocity()
{
	return _velocity;
}