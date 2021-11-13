#ifndef DATA_TABLES_HPP
#define DATA_TABLES_HPP

#include "GameHeaders/ResourceIdentifiers.hpp"

struct AircraftData
{
	int hitpoints;
	float speed;
	sf::Time fireInterval;
	Textures::ID texture;
};

std::vector<AircraftData> initalizeAircraftData();
#endif