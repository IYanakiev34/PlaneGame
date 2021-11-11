#include "GameHeaders/Button.hpp"
#include "GameHeaders/Util.hpp"
namespace GUI
{
// Constructor
Button::Button(const TextureHolder& textures, const FontHolder& fonts) :
	mCallback(),
	mNormalTexture(textures.get(Textures::ButtonNormal)),
	mSelectedTexture(textures.get(Textures::ButtonSelected)),
	mPressedTexture(textures.get(Textures::ButtonPressed)),
	mSprite(),
	mText("", fonts.get(Fonts::Main), 16),
	mIsToggle(false)
{
	mSprite.setTexture(mNormalTexture);
	sf::FloatRect bounds = mSprite.getLocalBounds();

	mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}
// Button is selectable component
bool Button::isSelectable() const
{
	return true;
}
// we don't need to hanle any events
void Button::handleEvent(const sf::Event&)
{
}

// Setting selected and setting texture
void Button::select()
{
	Component::select();

	mSprite.setTexture(mSelectedTexture);
}

// Setting deselected and setting normal texture
void Button::deselect()
{
	Component::deselect();

	mSprite.setTexture(mNormalTexture);
}

// activating the button
void Button::activate()
{
	Component::activate();

	if (mIsToggle)
		mSprite.setTexture(mPressedTexture);
	if (mCallback)
		mCallback();
	if (!mIsToggle)
		deactivate();
}

void Button::deactivate()
{
	Component::deactivate();

	if (mIsToggle)
	{
		if (isSelected())
		{
			mSprite.setTexture(mSelectedTexture);
		}
		else
		{
			mSprite.setTexture(mNormalTexture);
		}
	}
}

void Button::setText(const std::string& text)
{
	mText.setString(text);
	centerOrigin(mText);
}

// Setter for toggle
void Button::setToggle(bool flag)
{
	mIsToggle = flag;
}

void Button::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}
// Drawing the button on screen
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(mSprite, states);
	target.draw(mText, states);
}
}