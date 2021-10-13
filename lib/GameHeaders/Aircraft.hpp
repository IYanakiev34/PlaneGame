#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include "ResourceIdentifiers.hpp"

class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};
	explicit Aircraft(Type type, const TextureHodler& textures);
	virtual void draw(sf::RenderTarget& target, sf::RenderState state) const;

private:
	Type _type;
	sf::Sprite _sprite;
}

#endif