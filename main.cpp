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
	App.setFramerateLimit(30);
	
	sf::Texture snakeTex;
	if( !snakeTex.loadFromFile("img/Aqua.png") ){
		std::cout << "Failed to load snake image file\n";
	}
	
	// Mighty snake warrior
	Snake snake(snakeTex, 10);
	
	while(App.isOpen()){
		sf::Event event;
		while( App.pollEvent(event) ){
			if(event.type == sf::Event::Closed){
				App.close();
			}
			
			snake.pollEvent(&event);
		}
		
		// Logic
		snake.logic();
		
		// Render
		App.clear( sf::Color(255, 255, 255) );
		//map.render(&App);
		snake.render(&App);
		
		App.display();
	}
	return 0;
}
