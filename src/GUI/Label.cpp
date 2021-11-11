#include "GameHeaders/Label.hpp"

namespace GUI
{
Label::Label(const std::string& text, const FontHolder& holder) :
	mText(text, holder.get(Fonts::Main))
{
}
bool Label::isSelectable() const
{
	return false;
}

void Label::handleEvent(const sf::Event&)
{
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(mText, states);
}

void Label::setText(const std::string& text)
{
	mText.setString(text);
}
}