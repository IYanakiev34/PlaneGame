#include "GameHeaders/World.hpp"

World::World(sf::RenderWindow& window) :
	mWindow(window),
	mWorldView(window.getDefaultView()),
	mTextures(),
	mSceneGraph(),
	mSceneLayers(),
	mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f),
	mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f),
	mScrollSpeed(-50.f),
	mPlayerAircraft(nullptr)
{
	loadTextures();
	buildScene();

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	// Scroll the world
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

	sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y -= 150.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += 150.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= 150.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += 150.f;
	}

	mPlayerAircraft->move(movement * dt.asSeconds());
	// Move the player sidewards (plane scouts follow the main aircraft)
	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	// If player touches borders, flip its X velocity
	if (position.x <= mWorldBounds.left + 150.f
		|| position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
	{
		velocity.x = -velocity.x;
		mPlayerAircraft->setVelocity(velocity);
	}

	// Apply movements
	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextures.load(Textures::Eagle, "content/Eagle.png");
	mTextures.load(Textures::Raptor, "content/Raptor.png");
	mTextures.load(Textures::Desert, "content/Desert.png");
}

void World::buildScene()
{
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	// Prepare the tiled background
	sf::Texture& texture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	// Add the background sprite to the scene
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	// Add player's aircraft
	std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures));
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mSceneLayers[Air]->attachChild(std::move(leader));
}