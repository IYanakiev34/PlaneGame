#ifndef LABEL_HPP
#define LABEL_HPP

#include "GameHeaders/Component.hpp"
#include "GameHeaders/ResourceHolder.hpp"
#include "GameHeaders/ResourceIdentifiers.hpp"

namespace GUI
{
class Label : public Component
{
public:
	typedef std::shared_ptr<Label> Ptr;

	Label(const std::string& text, const FontHolder& fonts);
	virtual bool isSelectable() const;
	virtual void handleEvent(const sf::Event& event);

	void setText(const std::string& text);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Text mText;
};
}

#endif
