#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
const float playerSpeed = 10;
#define PI 3.14159265
const int Y0 = 600 / 2;
const int X0 = 800 / 2;
class player
{
public:
	std::vector<bullet> bulletsshot;
	sf::Sprite shape;
	sf::Texture bulletTex;
	sf::Sprite bulletspr;
	sf::Vector2f lastpos;
	bool notpressedbefore;

	player(sf::Sprite spr,sf::Vector2f,sf::Sprite);
	~player();
	void update(std::vector<std::string>, sf::Keyboard&, sf::Mouse&, sf::RenderWindow&);
	void draw(sf::RenderWindow&);
};

