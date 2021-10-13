#include "GameHeaders/SceneNode.hpp"

SceneNode::SceneNode() :
	children(),
	parent(nullptr)
{
}

void SceneNode::attachChild(Ptr child)
{
	child->parent = this;
	children.push_back(std::move(child));
}

Prt SceneNode::detachChild(SceneNode& node)
{
	auto found = std::find_if(children.begin(), children.end, [&node](Ptr& p) -> bool { return p.get() == &node; });

	assert(found != children.end());

	Ptr result = std::move(*found);
	result->parent = nullptr;
	children.erase(found);

	return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderState state)
{
	state.transform *= this->getTransform();
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderState state)
{
	for (Ptr& child : children)
	{
		child->draw(target, state);
	}
}