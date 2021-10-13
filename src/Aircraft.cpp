#include "GameHeaders/Aircraft.hpp"

#include "ResourceIdentifiers.hpp"

Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
		case Aircraft::Eagle:
			return Textures::Eagle;
		case: Aircraft::Raptor :
			return Textures::Raptor;
	}
}

Aircraft::Aircraft(Type type, const TextureHolder& textures) :
	_type(type),
	_sprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2f, bounds.height / 2f);
}

void Aircraft::draw(sf::RenderTarget& target, sf::RenderState state)
{
	target.draw(mSprite, state);
}