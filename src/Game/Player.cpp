#include "GameHeaders/Player.hpp"
#include "GameHeaders/Aircraft.hpp"
#include "GameHeaders/Command.hpp"
#include "GameHeaders/SceneNode.hpp"
struct AircraftMover
{
	AircraftMover(float vx, float vy) :
		velocity(vx, vy)
	{
	}
	void operator()(SceneNode& node, sf::Time)
	{
		Aircraft& aircraft = static_cast<Aircraft&>(node);
		aircraft.setVelocity(velocity + aircraft.getVelocity());
	}
	sf::Vector2f velocity;
};

Player::Player()
{
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed
		&& event.key.code == sf::Keyboard::P)
	{
		Command output;
		output.category = Category::PlayerAircraft;
		output.action = [](SceneNode& s, sf::Time) {
			std::cout << s.getPosition().x << ","
					  << s.getPosition().y << "\n";
		};
		commands.push(output);
	}
}

void Player::hanldeRealTimeInput(CommandQueue& commands)
{
	const float playerSpeed = 30.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Command moveLeft;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = AircraftMover(-playerSpeed, 0.f);
		commands.push(moveLeft);
	}
}