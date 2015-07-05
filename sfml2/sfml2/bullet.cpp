#include "bullet.h"


bullet::bullet(int angle,sf::Vector2f position,sf::Sprite bulletspite)
{
	//this->shape=shape;
	//(*this).shape=shape;
	shape = bulletspite;
	pos = position;
	
	shape.setPosition(pos);
	shape.setRotation(angle);

	float rad = angle *Pi / 180;

	vel.x = bulletSpeed*(cos(rad)) ;
	vel.y = bulletSpeed*(sin(rad));
}


bullet::~bullet()
{
	
}
bool bullet::update(std::vector<std::string>map){

	shape.move(vel);
	pos = shape.getPosition();
	sf::RectangleShape here;
	here.setSize(sf::Vector2f(25, 25));
	sf::Vector2f herepos;
	for (int i = 0; i < map.size(); i++){
		for (int j = 0; j < map[i].length(); j++){
			
			if (map[i][j] == '1' || map[i][j] =='2'){
				//std::cout << "got here" << std::endl;
				herepos.x = j*25;
				herepos.y = i*25;
				here.setPosition(herepos);
				if (here.getGlobalBounds().intersects(shape.getGlobalBounds())){
					return true;
				}
				
			}

		}
	}
	
	if (pos.x > 800 || pos.x < 0 || pos.y < 0 || pos.y > 600)
		return true;
	return false;
	
}