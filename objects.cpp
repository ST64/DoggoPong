#include "objects.h"
Ball::Ball(std::string sprfile){
	dist = std::uniform_real_distribution<float>(0.0f,1.0f);
	gen.seed(clk::now().time_since_epoch().count());
	left = 489.0f;
	top = 422.0f;
	width=84;
	height=84;
	deltax = 1.0f + (dist(gen))*2.0;
	deltay = (dist(gen))*2.0;
	tex = new sf::Texture;
	tex->loadFromFile(sprfile);
	spr = new sf::Sprite(*tex);
	spr->setPosition(left,top);
}
void Ball::reset(){
	left = 489.0f;
	top = 422.0f;
	deltax = 1.0f + dist(gen) * 2.0;
	deltay = dist(gen)*2.0;
}
void Ball::draw(sf::RenderWindow &w){
	spr->setPosition(left,top);
	w.draw(*spr);
}
void Ball::tick(Doggo *paddles, int &lscore, int &rscore){
	if (fabsf(deltax) > 20.0f){
		deltax = 20.0f * deltax / fabsf(deltax);
	}
	if (fabsf(deltay) > 20.0f){
		deltay = 20.0f * deltay / fabsf(deltay);
	}
	if ((paddles[0].intersects(*this))||(paddles[0].bodyrect.intersects(*this))){
		deltax = fabsf(deltax)*1.1f;
		deltay = (0.5-dist(gen)) * deltay / (0.5-dist(gen));
	}else if ((paddles[1].intersects(*this))||(paddles[1].bodyrect.intersects(*this))){
		deltax = -fabsf(deltax*1.1f);
		deltay = (0.5-dist(gen)) * deltay / (0.5-dist(gen));
	}else if (top > 716){
		deltay = -fabsf(deltay);
	}else if (top < 0){
		deltay = fabsf(deltay);
	}
	top += deltay;
	left += deltax;
	if (left < 0){
		lscore++;
		reset();
	}else if (left > 1200){
		rscore++;
		reset();
	}
}
Doggo::Doggo(std::string hsprfile, std::string bsprfile, sf::FloatRect brect){
	htex = new sf::Texture;
	btex = new sf::Texture;
	htex->loadFromFile(hsprfile);
	btex->loadFromFile(bsprfile);
	head = new sf::Sprite(*htex);
	body = new sf::Sprite(*btex);
	width=84;
	height=84;
	bodyrect = brect;
	body->setPosition(brect.left,brect.top);
	if (bodyrect.left == 25){
		bodyrect.left = 109;
	}
	top = 422;
	neck = new sf::RectangleShape;
	neck2 = new sf::RectangleShape;
	neck->setFillColor(sf::Color::Black);
	neck2->setFillColor(sf::Color::White);
	if (brect.left < 200){
		left = 109;
		neck->setPosition(109,522);
		neck2->setPosition(113,522);
	}else{
		left = 1087;
		neck->setPosition(1087,522);
		neck2->setPosition(1091,522);
	}
}
void Doggo::draw(sf::RenderWindow &w){
	head->setPosition(left,top);
	neck->setSize(sf::Vector2f(84.0f,top-422));
	neck2->setSize(sf::Vector2f(76.0f,top-422));
	if (bodyrect.left < 200){
		neck->setPosition(109,506);
		neck2->setPosition(113,506);
	}else{
		neck->setPosition(1087,506);
		neck2->setPosition(1091,506);
	}
	w.draw(*head);
	w.draw(*body);
	w.draw(*neck);
	w.draw(*neck2);
}
void Doggo::tick(uint8_t flags){
	if (flags & 1){
		if (top > 0){
			top -= 2;
		}
	}if (flags & 2){
		if (top < 422){
			top += 2;
		}
	}
}
