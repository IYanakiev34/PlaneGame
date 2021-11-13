#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include "GameHeaders/Entity.hpp"
#include "GameHeaders/ResourceHolder.hpp"
#include "GameHeaders/ResourceIdentifiers.hpp"
#include "GameHeaders/TextNode.hpp"
class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
		Avenger,
		TypeCount,
	};

public:
	Aircraft(Type type, const TextureHolder& textures);
	virtual unsigned int getCategory() const override;

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	Textures::ID toTextureID(Type type);

private:
	Type mType;
	sf::Sprite mSprite;
};

#endif