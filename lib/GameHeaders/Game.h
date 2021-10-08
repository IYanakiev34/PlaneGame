#ifndef GAME_H
#define GAME_H
class Game
{
public:
	// Constructors and destructors
	Game();
	virtual ~Game();

	// Functions
	void update();
	void render();

	//Getters and setters
	bool isRunning();

private:
	sf::RenderWindow* window;
	sf::Event ev;

	void initializeVariables();
	void initializeWindow();
	void updatePollEvents();
};

#endif