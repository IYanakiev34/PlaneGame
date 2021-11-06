#include "GameHeaders/Entity.hpp"

void Entity::setVelocity(float x, float y)
{
	m_velocity.x = x;
	m_velocity.y = y;
}
void Entity::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

sf::Vector2f Entity::getVelocity() const
{
	return m_velocity;
}

void Entity::updateCurrent(sf::Time dt)
{
	move(m_velocity * dt.asSeconds());
}