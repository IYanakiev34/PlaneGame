#ifndef SPRITE_NODE_HPP
#define SPRITE_NODE_HPP

#include "GameHeaders/SceneNode.hpp"
class SpriteNode : public SceneNode
{
public:
	explicit SpriteNode(const sf::Texture& texture);
	SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite mSprite;
};

#endif