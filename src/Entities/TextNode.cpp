#include "GameHeaders/TextNode.hpp"
#include "GameHeaders/Util.hpp"
TextNode::TextNode(const FontHolder& holder, const std::string& string)
{
	mText.setFont(holder.get(Fonts::Main));
	mText.setCharacterSize(20);
	setString(string);
}

void TextNode::setString(const std::string& text)
{
	mText.setString(text);
	centerOrigin(mText);
}

void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mText, states);
}