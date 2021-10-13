#include "GameHeaders/Game.hpp"
#include "GameHeaders/ResourceHolder.hpp"
#include "Platform/Platform.hpp"
namespace Textures
{
enum ID
{
	Airplane,
	Landscape
};
}

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	/*
	 * sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(200.0f * screenScalingFactor, 200.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window.getSystemHandle());*/

	Game game;
	game.run();
	return 0;
}