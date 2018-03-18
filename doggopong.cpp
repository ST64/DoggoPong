#include "objects.h"
#include <cmath>
#include <iostream>
#include <ctime>
#include <sstream>
int main(int argc, char *argv[]){
	sf::RenderWindow window(sf::VideoMode(1280,800),"Doggo Pongo", sf::Style::Titlebar | sf::Style::Close);
	int h = 422;
	int h2= 422;
	int lscore = 0;
	int rscore = 0;
	Ball b("doggo4.png");
	Doggo d[2] = {Doggo("doggo3.png","doggo2.png",sf::FloatRect(25,400,84,400)), Doggo("doggo4.png","doggo5.png",sf::FloatRect(1039,400,84,400))};
	sf::Font font;
	font.loadFromFile("test.ttf");
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			d[1].tick(1);
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			d[1].tick(2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			d[0].tick(1);
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			d[0].tick(2);
		}
		SS1.str("");
		SS1 << lscore;
		score1.setString(SS1.str());
		SS2.str("");
		SS2 << rscore;
		score2.setString(SS2.str());
		b.tick(d,lscore,rscore);
		while (window.pollEvent(event)){
			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
				window.close();
				break;
			}
		}
		window.clear(sf::Color(128,166,255));
		d[0].draw(window);
		d[1].draw(window);
		b.draw(window);
		window.draw(score1);
		window.draw(score2);
		window.display();
	}
	return 0;
}
