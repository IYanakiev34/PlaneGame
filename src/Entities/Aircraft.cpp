#include "GameHeaders/Aircraft.hpp"

#include <GameHeaders/ResourceHolder.hpp>

Aircraft::Aircraft(Type type, const TextureHolder& textures) :
	mType(type)
{
	mSprite.setTexture(textures.get(toTextureID(mType)));
	sf::FloatRect rect = mSprite.getLocalBounds();
	mSprite.setOrigin(rect.width / 2, rect.height / 2);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

Textures::ID Aircraft::toTextureID(Aircraft::Type type)
{
	switch (type)
	{
		case Aircraft::Eagle:
			return Textures::Eagle;

		case Aircraft::Raptor:
			return Textures::Raptor;
		default:
			break;
	}
	return Textures::Eagle;
}