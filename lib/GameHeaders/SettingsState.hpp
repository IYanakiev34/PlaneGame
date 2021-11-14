#ifndef SETTINGS_STATE_HPP
#define SETTINGS_STATE_HPP

#include "GameHeaders/Button.hpp"
#include "GameHeaders/Container.hpp"
#include "GameHeaders/Label.hpp"
#include "GameHeaders/Player.hpp"
#include "GameHeaders/State.hpp"

class SettingsState : public State
{
public:
	SettingsState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

private:
	void updateLabels();
	void addButtonLabel(Player::Action action, float y, const std::string& text, Context context);

private:
	sf::Sprite mBackgroundSprite;
	GUI::Container mGUIContainer;
	std::array<GUI::Button::Ptr, Player::ActionCount> mBindingButtons;
	std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabels;
};

#endif