#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "GameHeaders/Player.hpp"
#include "GameHeaders/ResourceHolder.hpp"
#include "GameHeaders/ResourceIdentifiers.hpp"
#include "GameHeaders/StateStack.hpp"

class Application
{
public:
	Application();
	void run();

private:
	void processInput();
	void update(sf::Time dt);
	void render();

	void updateStatistics(sf::Time dt);
	void registerStates();

private:
	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow;
	TextureHolder mTextures;
	FontHolder mFonts;
	Player mPlayer;

	StateStack mStateStack;

	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames;
};

#endif