#include "GameHeaders/Game.hpp"

Game::Game() :
	m_window(sf::VideoMode(640, 480), "SFML Application"),
	m_player(),
	isMovingUp(false),
	isMovingDown(false),
	isMovingLeft(false),
	isMovingRight(false),
	m_playerSpeed(200.f),
	TimePerFrame(sf::seconds(1.f / 60.f))
{
	if (!m_texture.loadFromFile("content/eagle.png"))
	{
		std::cout << "error loading from file!" << std::endl;
		exit(1);
	}
	m_player.setTexture(m_texture);
	m_player.setPosition(sf::Vector2f(100.f, 100.f));
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
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				m_window.close();
				break;
			default:
				break;
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool state)
{
	switch (key)
	{
		case sf::Keyboard::W:
			isMovingUp = state;
			break;
		case sf::Keyboard::S:
			isMovingDown = state;
			break;
		case sf::Keyboard::A:
			isMovingLeft = state;
			break;
		case sf::Keyboard::D:
			isMovingRight = state;
			break;
		default:
			break;
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (isMovingUp)
		movement.y -= m_playerSpeed;
	if (isMovingDown)
		movement.y += m_playerSpeed;
	if (isMovingRight)
		movement.x += m_playerSpeed;
	if (isMovingLeft)
		movement.x -= m_playerSpeed;

	m_player.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_player);
	m_window.display();
}