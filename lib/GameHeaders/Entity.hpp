#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity : public SceneNode
{
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float x, float y);

	sf::Vector2f getVelocity();

private:
	sf::Vector2f _velocity;
}

#endif