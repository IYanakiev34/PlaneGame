#include "GameHeaders/Game.hpp"

//Constructors
Game::Game() :
	window(sf::VideoMode(800, 600), "First Game", sf::Style::Titlebar | sf::Style::Close),
	isMovingUp(false),
	isMovingDown(false),
	isMovingLeft(false),
	isMovingRight(false),
	TimePerFrame(sf::seconds(1.0f / 60.0f)),
	PlayerSpeed(100.0f),
	texture(),
	player()
{
	if (!texture.loadFromFile("content/player.png"))
	{
		throw std::runtime_error("couldn't load the player from the file!");
	}
	player.setTexture(texture);
	player.setScale(sf::Vector2f(4.0f, 4.0f));
	player.setPosition(300.0f, 300.0f);
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastFrame = sf::Time::Zero;

	while (window.isOpen())
	{
		processEvents();
		timeSinceLastFrame += clock.restart();
		while (timeSinceLastFrame > TimePerFrame)
		{
			timeSinceLastFrame -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerMovement(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerMovement(event.key.code, false);
				break;
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (isMovingUp)
		movement.y -= PlayerSpeed;
	if (isMovingDown)
		movement.y += PlayerSpeed;
	if (isMovingLeft)
		movement.x -= PlayerSpeed;
	if (isMovingRight)
		movement.x += PlayerSpeed;

	player.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	window.clear();
	window.draw(player);
	window.display();
}

void Game::handlePlayerMovement(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		isMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		isMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		isMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		isMovingRight = isPressed;
}
