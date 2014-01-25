#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "map.h"
#include "tile.h"
#include "snake.h"

#define DEBUG_WINDOW = true;

constexpr float pixelToScale(float imgSize, const int &size){
	return (1/imgSize)*size;
}

const int TILE_SIZE = 16;

int main(){
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Snake");
	App.setFramerateLimit(30);
	
	sf::Texture snakeTex;
	if( !snakeTex.loadFromFile("img/Aqua.png") ){
		std::cerr << "Failed to load snake image file\n";
		return -1;
	}
	
	// Mighty snake warrior
	Snake snake;
	const float s = pixelToScale(snakeTex.getSize().x, TILE_SIZE);
	snake.setSquareSize(TILE_SIZE);
	snake.setScale({s,s});
	snake.createSprite(snakeTex);
	snake.reset(10);
	snake.setSpeed(5);

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
