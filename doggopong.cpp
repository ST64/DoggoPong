#include <SFML/Graphics.hpp>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
int main(int argc, char *argv[]){
	std::srand(std::time(0));
	sf::RenderWindow window(sf::VideoMode(1280,800),"Doggo Pongo", sf::Style::Titlebar | sf::Style::Close);
	int h = 422;
	int h2= 422;
	double deltax = std::rand();
	deltax = 0.5 + (deltax / (double)RAND_MAX);
	double deltay = std::rand();
	deltay = (deltay / (double)RAND_MAX);
	double x = 489;
	double y = 422;
	int lscore = 0;
	int rscore = 0;
	sf::Sprite headsprite, doggosprite, headsprite2, doggosprite2, headsprite3;
	sf::Texture headtex, doggotex, headtex2, doggotex2, headtex3;
	headtex.loadFromFile("doggo3.png");
	headtex2.loadFromFile("doggo4.png");
	headtex3.loadFromFile("doggo4.png");
	doggotex.loadFromFile("doggo2.png");
	doggotex2.loadFromFile("doggo5.png");
	headsprite.setTexture(headtex);
	headsprite2.setTexture(headtex2);
	headsprite3.setTexture(headtex3);
	doggosprite.setTexture(doggotex);
	doggosprite2.setTexture(doggotex2);
	doggosprite.setPosition(25,400);
	doggosprite2.setPosition(1039,400);
	headsprite3.setPosition(x,y);
	headsprite2.setPosition(1087,h2);
	headsprite.setPosition(109,h);
	sf::Font font;
	font.loadFromFile("test.ttf");
	sf::RectangleShape neck, neck2, neck3, neck4;
	neck2.setFillColor(sf::Color::White);
	neck4.setFillColor(sf::Color::White);
	neck.setFillColor(sf::Color::Black);
	neck3.setFillColor(sf::Color::Black);
	neck.setPosition(109,522);
	neck4.setPosition(1087,522);
	neck3.setPosition(1083,522);
	neck2.setPosition(113,522);
	std::stringstream SS1;
	std::stringstream SS2;
	SS1.str("0");
	SS2.str("0");
	sf::Text score1(SS1.str(),font,50);
	sf::Text score2(SS2.str(),font,50);
	score1.setPosition(0,0);
	score2.setPosition(1087,0);
	score1.setFillColor(sf::Color::Black);
	score2.setFillColor(sf::Color::Black);
	while (window.isOpen()){
		sf::Event event;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (h2 < 844)){
			h2+=2;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (h2 > 422)){
			h2-=2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (h < 844)){
			h += 2;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (h > 422)){
			h -= 2;
		}
		x += deltax;
		y += deltay;
		double ran = std::rand();
		ran = ran / ((double)RAND_MAX);
		double ran2 = std::rand();
		ran2 = ran2 / ((double)RAND_MAX);
		if (x < 0){
			lscore++;
			SS1.str("");
			SS1 << lscore;
			score1.setString(SS1.str());
			deltax = 0.5 + (double)(std::rand())/(double)(RAND_MAX);
			deltay = (double)(std::rand())/(double)(RAND_MAX);
			x = 489;
			y = 422;
		}else if (x > 1200){
			rscore++;
			SS2.str("");
			SS2 << rscore;
			score2.setString(SS2.str());
			x = 489;
			y = 422;
			deltax = -0.5 - (double)(std::rand())/(double)(RAND_MAX);
			deltay = (double)(std::rand())/(double)(RAND_MAX);
		}else if ((x < 193) && ((y < 844-h) && (y > 760-h) || (y > 422))){
			deltax = fabs(deltax);
			deltax = deltax + ran/20.0;
			deltay = deltay + (0.5-ran2);
		}else if (y < 0){
			deltay = fabs(deltay);
		}else if (y > 716){
			deltay = 0.0-fabs(deltay);
		}else if ((x > 1003) && ((y < 844-h2) && (y > 760-h2) || (y > 422))){
			deltax = -fabs(deltax);
			deltax = deltax - (ran)/20.0;
			deltay = deltay + (0.5-ran2);
		}
		x += deltax;
		y += deltay;
		headsprite.setPosition(109,844-h);
		headsprite2.setPosition(1087,844-h2);
		headsprite3.setPosition(x,y);
		while (window.pollEvent(event)){
			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
				window.close();
				break;
			}
		}
		neck.setSize(sf::Vector2f(84,h-422));
		neck3.setSize(sf::Vector2f(84,h2-422));
		neck2.setSize(sf::Vector2f(76,h-422));
		neck4.setSize(sf::Vector2f(76,h2-422));
		neck.setPosition(109,928-h);
		neck3.setPosition(1087,928-h2);
		neck2.setPosition(113,928-h);
		neck4.setPosition(1091,928-h2);
		window.clear(sf::Color(128,166,255));
		window.draw(doggosprite);
		window.draw(doggosprite2);
		window.draw(headsprite);
		window.draw(headsprite2);
		window.draw(headsprite3);
		window.draw(neck);
		window.draw(neck2);
		window.draw(neck3);
		window.draw(neck4);
		window.draw(score1);
		window.draw(score2);
		window.display();
	}
	return 0;
}
