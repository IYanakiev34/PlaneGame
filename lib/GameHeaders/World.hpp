#ifndef WORLD_HPP
#define WORLD_HPP

#include "GameHeaders/Aircraft.hpp"
#include "GameHeaders/CommandQueue.hpp"
#include "GameHeaders/ResourceHolder.hpp"
#include "GameHeaders/ResourceIdentifiers.hpp"
#include "GameHeaders/SceneNode.hpp"
#include "GameHeaders/SpriteNode.hpp"
class World : private sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);
	CommandQueue& getCommandQueue();
	void update(sf::Time dt);
	void draw();

private:
	void loadTextures();
	void buildScene();
	void adaptPlayerVelocity();
	void adaptPlayerPosition();

private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;
	CommandQueue mCommandQueue;
};

#endif