#ifndef UTIL_HPP
#define UTIL_HPP

#include <sstream>

namespace sf
{
class Sprite;
class Text;
}

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

std::string toString(sf::Keyboard::Key key);
void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

#include <GameHeaders/Util.inl>
#endif