#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "GameHeaders/Entity.hpp"
#include "GameHeaders/ResourceIdentifiers.hpp"

class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};

public:
	Aircraft(Type type, const TextureHolder& textures);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	Textures::ID toTextureID(Type type);

private:
	Type mType;
	sf::Sprite mSprite;
};

#endif