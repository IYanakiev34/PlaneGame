#ifndef GAME_HPP
#define GAME_HPP

#include "GameHeaders/World.hpp"
class Game : private sf::NonCopyable
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time);
	void render();

	//void handlePlayerInput(sf::Keyboard::Key key, bool state);

private:
	sf::RenderWindow m_window;
	World mWorld;
	sf::Time TimePerFrame;
};

#endif