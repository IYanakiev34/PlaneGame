#include "GameHeaders/Player.hpp"

struct AircraftMover
{
	AircraftMover(float vx, float vy) :
		velocity(vx, vy)
	{
	}
	void operator()(SceneNode& node, sf::Time dt)
	{
		Aircraft& aircraft = static_cast<Aircraft&>(node);
		aircraft.accelerate(velocity * dt.asSeconds());
	}
	sf::Vector2f velocity;
};

Player::Player()
{
	// initial key bindings
	mKeyBindings[sf::Keyboard::Left] = MoveLeft;
	mKeyBindings[sf::Keyboard::Right] = MoveRight;
	mKeyBindings[sf::Keyboard::Up] = MoveUp;
	mKeyBindings[sf::Keyboard::Down] = MoveDown;

	initializeActions();

	// Assign all categories to player's aircraft
	for (auto& pair : mActionBindings)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		// Check if pressed key appears in key binding, trigger command if so
		auto found = mKeyBindings.find(event.key.code);
		if (found != mKeyBindings.end() && !isRealTimeAction(found->second))
			commands.push(mActionBindings[found->second]);
	}
}

void Player::hanldeRealTimeInput(CommandQueue& commands)
{
	for (auto pair : mKeyBindings)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealTimeAction(pair.second))
			commands.push(mActionBindings[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	for (auto itr = mKeyBindings.begin(); itr != mKeyBindings.end(); itr++)
	{
		if (itr->second == action)
			mKeyBindings.erase(itr);
	}

	mKeyBindings[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	for (auto p : mKeyBindings)
		if (p.second == action)
			return p.first;

	return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
	const float playerSpeed = 200.f;

	mActionBindings[MoveLeft].action = AircraftMover(-playerSpeed, 0.f);
	mActionBindings[MoveRight].action = AircraftMover(+playerSpeed, 0.f);
	mActionBindings[MoveUp].action = AircraftMover(0.f, -playerSpeed);
	mActionBindings[MoveDown].action = AircraftMover(0.f, +playerSpeed);
}
bool Player::isRealTimeAction(Action action)
{
	switch (action)
	{
		case MoveLeft:
		case MoveRight:
		case MoveUp:
		case MoveDown:
			return true;
		default:
			return false;
	};
}