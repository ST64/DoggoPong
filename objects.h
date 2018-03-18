#ifndef DOGGOPONG_OBJS_H
#define DOGGOPONG_OBJS_H
#include <SFML/Graphics.hpp>
#include <cstdint>
#include <random>
#include <chrono>
#include <iostream>
typedef std::chrono::high_resolution_clock clk;
class Doggo : public sf::FloatRect{
	public:
	Doggo(std::string hsprfile, std::string bsprfile, sf::FloatRect brect);
	void draw(sf::RenderWindow &w);
	void tick(uint8_t flags);
	sf::Sprite *head, *body;
	sf::RectangleShape *neck, *neck2;
	sf::Texture *htex, *btex;
	sf::FloatRect bodyrect;
};
class Ball : public sf::FloatRect{
	public:
	Ball(std::string sprfile);
	void draw(sf::RenderWindow &w);
	void tick(Doggo *paddles, int &lscore, int &rscore);
	void reset();
	float deltax;
	float deltay;
	sf::Sprite *spr;
	sf::Texture *tex;
	std::default_random_engine gen;
	std::uniform_real_distribution<float> dist;
};
#endif
