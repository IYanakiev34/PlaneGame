#ifndef SCENENODE_HPP
#define SCENENODE_HPP

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;
	SceneNode();
	void attachChild(Ptr child);
	Prt detachChild(SceneNode& node);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderState state) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderState state) const;
	std::vector<Ptr> children;
	SceneNode* parent;
}

#endif