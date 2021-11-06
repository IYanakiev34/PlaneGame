#include "GameHeaders/SceneNode.hpp"

SceneNode::SceneNode() :
	mChildren(),
	mParent(nullptr)
{
}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) { return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}
// update the whole node
void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

// update current (int this case since its a node class we do nothing)
void SceneNode::updateCurrent(sf::Time dt)
{
	// we use this in order to avoid to unused variable error
	dt = dt;
}

// update the children (invoke update method on each one of them)
void SceneNode::updateChildren(sf::Time dt)
{
	for (Ptr& child : mChildren)
	{
		child->update(dt);
	}
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Apply transform of current node
	states.transform *= getTransform();

	// Draw node and children with changed transform
	drawCurrent(target, states);
	drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget&, sf::RenderStates) const
{
	// Do nothing by default
}

// draw children
void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const Ptr& child : mChildren)
	{
		child->draw(target, states);
	}
}

// multiplies transforms from root to this node in order ot get its absolute transform
sf::Transform SceneNode::getWorldTransform() const
{
	// identity transform does nothing but its here for clarity
	sf::Transform transform = sf::Transform::Identity;

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
	{
		transform = node->getTransform() * transform;
	}

	return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}
