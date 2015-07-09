#include "player.h"


player::player(sf::Sprite sprite,sf::Vector2f pos,sf::Sprite bulletsprite)
{
	shape = sprite;
	shape.setPosition(pos);
	
	
	bulletTex.loadFromFile("bullet.png");
	bulletsprite.setTexture(bulletTex);
	lastpos = pos;
	bulletspr = bulletsprite;
	shape.setOrigin(sf::Vector2f(60, 41));
	notpressedbefore = false;
}


player::~player()
{
}
void player::update(std::vector<std::string>map, sf::Keyboard& keyb, sf::Mouse& mous, sf::RenderWindow& win){
	sf::Vector2i curpos = mous.getPosition(win);
	sf::Vector2f playpos = shape.getPosition();
	float dx = playpos.x - curpos.x;
	float dy = playpos.y - curpos.y;

	double angle = (atan2(dy, dx)) * 180 / PI;
	shape.setRotation(angle+180);

	if (keyb.isKeyPressed(keyb.W)){
		shape.move(sf::Vector2f(0,-playerSpeed));
	}
	if (keyb.isKeyPressed(keyb.S)){
		shape.move(sf::Vector2f(0, playerSpeed));
	}
	if (keyb.isKeyPressed(keyb.D)){
		shape.move(sf::Vector2f(playerSpeed, 0));
	}
	if (keyb.isKeyPressed(keyb.A)){
		shape.move(sf::Vector2f(-playerSpeed, 0));
	}


	if (mous.isButtonPressed(mous.Left) && !notpressedbefore){
		bullet shot(angle+180, shape.getPosition(), bulletspr);
		bulletsshot.push_back(shot);
	}
	notpressedbefore = mous.isButtonPressed(mous.Left);
	bool eh = false;
	sf::RectangleShape hereShape;
	hereShape.setSize(sf::Vector2f(25, 25));
	for (int i = 0; i < map.size(); i++){
		for (int j = 0; j < map[i].length(); j++){
			if (map[i].at(j) == '1' || map[i].at(j) == '2' ){
				sf::Vector2f here(j * 25, i * 25);
				hereShape.setPosition(here);
				int rot = shape.getRotation();
				shape.setRotation(0);
				if (hereShape.getGlobalBounds().intersects(shape.getGlobalBounds())){
					std::cout << "STOP TOUCH WALL " << std::endl;
					/*
					//shape.setOrigin(sf::Vector2f(0, 0));
					int xx = shape.getPosition().x - here.x;
					int yy = shape.getPosition().y - here.y;

					int px = shape.getPosition().x;
					int py = shape.getPosition().y;

					if (xx <= 0){
						
						shape.setPosition(lastpos);
					}
					else{
						shape.setPosition(lastpos);
					}

					if (yy <= 0){
						shape.setPosition(lastpos);
					}
					else{
						shape.setPosition(lastpos);
					}
					*/
					shape.setPosition(lastpos);
					eh = true;
					//shape.setOrigin(sf::Vector2f(60, 41));
				}
				shape.setRotation(rot);
			}
		}
	}

	for (int i = 0; i < bulletsshot.size(); i++){
		bool destroyed=bulletsshot[i].update(map);
		if (destroyed){
			bulletsshot.erase(bulletsshot.begin()+i);
		}
	}
	if (!eh)
		lastpos = shape.getPosition();
	
}
void player::draw(sf::RenderWindow& a){
	for (int i = 0; i < bulletsshot.size(); i++){
		a.draw(bulletsshot[i].shape);
	}
	a.draw(shape);
}
