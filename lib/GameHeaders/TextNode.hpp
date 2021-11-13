#ifndef TEXT_NODE_HPP
#define TEXT_NODE_HPP

#include "GameHeaders/ResourceHolder.hpp"
#include "GameHeaders/ResourceIdentifiers.hpp"
#include "GameHeaders/SceneNode.hpp"
class TextNode : public SceneNode
{

public:
	explicit TextNode(const FontHolder& fonts, const std::string& string);
	void setString(const std::string& text);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Text mText;
};

#endif