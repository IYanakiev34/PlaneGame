#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "GameHeaders/Component.hpp"
#include "GameHeaders/ResourceHolder.hpp"
#include "GameHeaders/ResourceIdentifiers.hpp"

namespace GUI
{

class Button : public Component
{
public:
	typedef std::shared_ptr<Button> Ptr;
	typedef std::function<void()> Callback;

	Button(const TextureHolder& textures, const FontHolder& holder);

	virtual bool isSelectable() const;
	virtual void handleEvent(const sf::Event& event);
	virtual void select();
	virtual void deselect();
	virtual void activate();
	virtual void deactivate();

	void setToggle(bool flad);
	void setText(const std::string& text);
	void setCallback(Callback callback);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Callback mCallback;
	const sf::Texture& mNormalTexture;
	const sf::Texture& mSelectedTexture;
	const sf::Texture& mPressedTexture;
	sf::Sprite mSprite;
	sf::Text mText;
	bool mIsToggle;
};
}

#endif