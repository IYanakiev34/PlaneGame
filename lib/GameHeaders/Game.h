#ifndef GAME_H
#define GAME_H
class Game
{
public:
	// Constructors and destructors
	Game();
	virtual ~Game();
	void run();

private:
	sf::RenderWindow window;
	bool isMovingUp, isMovingDown, isMovingLeft, isMovingRight;
	const sf::Time TimePerFrame;
	const float PlayerSpeed;
	sf::Texture texture;
	sf::Sprite player;

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerMovement(sf::Keyboard::Key key, bool isPressed);
};

#endif