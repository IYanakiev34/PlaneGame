#include "GameHeaders/MenuState.hpp"
#include "GameHeaders/Button.hpp"
#include "GameHeaders/ResourceHolder.hpp"
#include "GameHeaders/Util.hpp"

MenuState::MenuState(StateStack& stack, Context context) :
	State(stack, context),
	mGUIContainer()

{
	sf::Texture& texture = context.textures->get(Textures::TitleScreen);
	mBackgroundSprite.setTexture(texture);

	auto playButton = std::make_shared<GUI::Button>(*context.textures, *context.fonts);
	playButton->setPosition(100, 250);
	playButton->setText("Play");
	playButton->setCallback([this]() {
		requestStackPop();
		requestStackPush(States::Game);
	});

	auto settingsButton = std::make_shared<GUI::Button>(*context.textures, *context.fonts);
	settingsButton->setPosition(100, 300);
	settingsButton->setText("Settings");
	settingsButton->setCallback([this]() {
		requestStackPop();
		requestStackPush(States::Settings);
	});

	auto exitButton = std::make_shared<GUI::Button>(*context.textures, *context.fonts);
	exitButton->setPosition(100, 350);
	exitButton->setText("Exit");
	exitButton->setCallback([this]() {
		requestStackPop();
	});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(settingsButton);
	mGUIContainer.pack(exitButton);
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool MenuState::update(sf::Time)
{
	return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	mGUIContainer.handleEvent(event);
	return false;
}