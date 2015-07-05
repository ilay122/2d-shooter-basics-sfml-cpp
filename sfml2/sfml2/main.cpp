#include <SFML/Graphics.hpp>
#include "player.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "2D shooter ?");
	window.setFramerateLimit(60);

	std::vector<std::string> map;
	

	std::string line;
	std::ifstream myfile("map.txt");
	int row = 0;
	while (getline(myfile, line))
	{
		std::cout << line << '\n';
		map.push_back(line);
		
	}
	myfile.close();

	sf::Texture playertex;
	playertex.loadFromFile("player.png");
	sf::Sprite playersprite;
	playersprite.setTexture(playertex);
	

	sf::Texture bullettex;
	bullettex.loadFromFile("bullet.png");
	sf::Sprite bulletsprite;
	bulletsprite.setTexture(bullettex);
	
 
	player userplay(playersprite, sf::Vector2f(300, 300),bulletsprite);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		userplay.update(map, sf::Keyboard(), sf::Mouse(),window);
		userplay.draw(window);
		sf::RectangleShape hereShape;
		sf::Vector2f here;
		hereShape.setSize(sf::Vector2f(25, 25));
		
		

		for (int i = 0; i < map.size(); i++){
			for (int j = 0; j < map[i].length(); j++){
				
				if (map[i].at(j) == '1'){
					here.x = j * 25;
					here.y = i * 25;
					hereShape.setFillColor(sf::Color::Yellow);
					hereShape.setPosition(here);
					window.draw(hereShape);
				}
				else if (map[i].at(j) == '2'){
					here.x = j * 25;
					here.y = i * 25;
					sf::Color rand(rand(), rand(), rand());

					//hereShape.setFillColor(sf::Color::Green);
					hereShape.setFillColor(rand);
					hereShape.setPosition(here);
					window.draw(hereShape);
				}
			}
		}
		window.display();
	}

	return 0;
}