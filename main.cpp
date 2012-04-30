#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "map.h"
#include "tile.h"
#include "snake.h"

int main(){
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Snake");
	
	sf::Image mapTiles;
	if( !mapTiles.LoadFromFile("spritesheet.png") ){
		//exit
	}
	
	
	sf::Sprite spr(mapTiles);
	Map map( spr );
	map.openFile("map/level1.map");
	
	// Mighty snake warrior
	Snake snakeWarrior;
	
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
		App.Clear( sf::Color(0, 0, 0) );
		map.render(&App);
		snakeWarrior.render(&App);
		
		App.Display();
	}
	return 0;
}
