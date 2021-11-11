#include "GameHeaders/Container.hpp"
namespace GUI
{
Container::Container() :
	mChildren(),
	mSelectedChild(-1)
{
}

void Container::pack(Component::Ptr component)
{
	mChildren.push_back(component);

	if (!hasSelection() && component->isSelectable())
		select(mChildren.size() - 1);
}

void Container::handleEvent(const sf::Event& event)
{
	if (hasSelection() && mChildren[mSelectedChild]->isActive())
	{
		mChildren[mSelectedChild]->handleEvent(event);
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
		{
			selectPrevious();
		}
		else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
		{
			selectNext();
		}
		else if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Return)
		{
			if (hasSelection())
				mChildren[mSelectedChild]->activate();
		}
	}
}
bool Container::isSelectable() const
{
	return false;
}
void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	for (const Component::Ptr& child : mChildren)
	{
		target.draw(*child); //dereference isnce Ptr is a pointer to an object
	}
}

void Container::select(std::size_t index)
{
	if (mChildren[index]->isSelectable())
	{
		if (hasSelection())
			mChildren[mSelectedChild]->deselect();

		mChildren[index]->select();
		mSelectedChild = index;
	}
}

void Container::selectNext()
{
	if (!hasSelection())
		return;
	// Search next component that is selectable
	int next = mSelectedChild;
	do
		next = (next + 1) % mChildren.size();
	while (!mChildren[next]->isSelectable());
	// Select that component
	select(next);
}

void Container::selectPrevious()
{
	if (!hasSelection())
		return;
	int previouos = mSelectedChild;
	do
		previouos = (previouos - 1) % mChildren.size();
	while (!mChildren[previouos]->isSelectable());

	select(previouos);
}
bool Container::hasSelection() const
{
	return mSelectedChild >= 0;
}
}
