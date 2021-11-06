#ifndef GAME_H
#define GAME_H

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time);
	void render();

	void handlePlayerInput(sf::Keyboard::Key key, bool state);

private:
	sf::RenderWindow m_window;
	sf::Texture m_texture;
	sf::Sprite m_player;

private:
	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;
	float m_playerSpeed;
	sf::Time TimePerFrame;
};

#endif