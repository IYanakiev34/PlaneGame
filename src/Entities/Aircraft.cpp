#include "GameHeaders/Aircraft.hpp"

#include <GameHeaders/ResourceHolder.hpp>

Aircraft::Aircraft(Type type, const TextureHolder& textures) :
	mType(type)
{
	mSprite.setTexture(textures.get(toTextureID(mType)));
	sf::FloatRect rect = mSprite.getLocalBounds();
	mSprite.setOrigin(rect.width / 2, rect.height / 2);
}

// drawing  the current  node AKA the aircraft itself
void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

//Converting from type to the speicif texture type we need
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

// Getting the category of the aircraft
unsigned int Aircraft::getCategory() const
{
	switch (mType)
	{
		case Aircraft::Eagle:
			return Category::PlayerAircraft;
		default:
			return Category::EnemyAircraft;
	}
}