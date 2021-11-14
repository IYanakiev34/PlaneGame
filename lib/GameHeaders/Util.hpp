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

float toDegree(float radian);
float toRadian(float degree);
int randomInt(int exclusiveMax);
float vectorLength(sf::Vector2f vec);
sf::Vector2f unitVector(sf::Vector2f vec);

#include <GameHeaders/Util.inl>
#endif