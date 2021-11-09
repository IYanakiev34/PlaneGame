#include "GameHeaders/Game.hpp"

Game::Game() :
	m_window(sf::VideoMode(640, 480), "SFML Application"),
	mWorld(m_window),
	TimePerFrame(sf::seconds(1.f / 60.f))
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	CommandQueue& commands = mWorld.getCommandQueue();

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		mPlayer.handleEvent(event, commands);

		if (event.type == sf::Event::Closed)
			m_window.close();
	}

	mPlayer.hanldeRealTimeInput(commands);
}

void Game::update(sf::Time deltaTime)
{
	mWorld.update(deltaTime);
}

void Game::render()
{
	m_window.clear();
	mWorld.draw();
	m_window.setView(m_window.getDefaultView());
	m_window.display();
}