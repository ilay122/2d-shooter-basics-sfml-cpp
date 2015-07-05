#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//angle = atan(diff.y/diff.x) * 180 / PI;
const float bulletSpeed = 10.0f;
const float Pi = 3.14159265;
class bullet
{
public:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Sprite shape;
	bullet(int angle,sf::Vector2f pos,sf::Sprite sprite );
	~bullet();
	bool update(std::vector<std::string>);
};

