#include "GameHeaders/Game.h"

//Constructors
Game::Game()
{
	initializeVariables();
	initializeWindow();
}

Game::~Game()
{
	delete this->window;
}

// updates and render
void Game::update()
{
	this->updatePollEvents();
}

void Game::updatePollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

void Game::render()
{
	this->window->clear(sf::Color::Cyan);

	//we need to draw here!

	this->window->display();
}

//initializations
void Game::initializeVariables()
{
	this->window = nullptr;
}

void Game::initializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game", sf::Style::Titlebar | sf::Style::Close);
}

bool Game::isRunning()
{
	return (bool)this->window->isOpen();
}