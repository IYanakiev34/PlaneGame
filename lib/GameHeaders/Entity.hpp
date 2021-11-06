#ifndef ENTITY_H
#define ENTITY_H

#include "GameHeaders/SceneNode.hpp"
class Entity : public SceneNode
{
public:
	void setVelocity(float x, float y);
	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getVelocity() const;

private:
	virtual void updateCurrent(sf::Time dt);

private:
	sf::Vector2f m_velocity;
};

#endif