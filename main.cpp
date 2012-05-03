#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "map.h"
#include "tile.h"
#include "snake.h"

#define DEBUG_WINDOW = true;

int main(){
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Snake");
	App.SetFramerateLimit(30);
	
	sf::Image snakeImage;
	if( !snakeImage.LoadFromFile("img/Aqua.png") ){
		std::cout << "Failed to load snake image file\n";
	}
	
	// Mighty snake warrior
	Snake snakeWarrior;
	snakeWarrior.setSprite(sf::Sprite(snakeImage), 10);
	
	while( App.IsOpened() ){
		//event polling
		sf::Event event;
		while( App.GetEvent(event) ){
			if(event.Type == sf::Event::Closed){
				App.Close();
			}
			
			snakeWarrior.pollEvent(&event);
		}
		
		//logic
		snakeWarrior.logic();
		
		//render
		App.Clear( sf::Color(255, 255, 255) );
		//map.render(&App);
		snakeWarrior.render(&App);
		
		App.Display();
	}
	return 0;
}
