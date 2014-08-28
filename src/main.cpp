#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "map.h"
#include "tile.h"
#include "snake.h"
#include "food.h"
#include "world.h"

#define DEBUG_WINDOW = true;

constexpr float pixelToScale( float imgSize, const int &size ){
	return ( 1 / imgSize ) * size;
}

const int TILE_SIZE = 16;

int main(){
	sf::RenderWindow App( sf::VideoMode( 800, 600, 32 ), "Snake" );
	std::cout << "f1\n";
	App.setFramerateLimit( 30 );
	std::cout << "f2\n";
	sf::Texture snakeTex;
	std::cout << "f2.1\n";
	if( !snakeTex.loadFromFile( "img/Silver.png" ) ){
		std::cout << "f2.2\n";
		return -1;
	}
	std::cout << "f3\n";
	snakeTex.setSmooth( false );
	std::cout << "f2\n";
	World world( &App );
	std::cout << "f3\n";
	FoodManager foodManager;
	foodManager.setBadFoodPerc( 10 );
	foodManager.setFoodGenTime( sf::seconds( 15 ) );
	std::cout << "f4\n";
	// Mighty snake warrior
	Snake snake(&foodManager);
	const float s = pixelToScale( snakeTex.getSize().x, TILE_SIZE );
	snake.setScale( {s, s} );
	snake.setSquareSize( TILE_SIZE );
	snake.createSprite( snakeTex );
	snake.reset( 10 );
	snake.setSpeed( 5 );
	std::cout << "f5\n";
	while( App.isOpen() ){
		std::cout << "f6\n";
		// Event
		sf::Event event;
		while( App.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				App.close();
			}
			
			snake.pollEvent( &event );
		}
		std::cout << "f7\n";
		// Logic
		foodManager.logic();
		snake.logic();
		std::cout << "f8\n";
		// Render
		//App.clear( sf::Color( 255, 255, 255 ) );

		std::cout << "f9\n";
		foodManager.render( &App );
		snake.render( &App );
		world.render();
		std::cout << "f10\n";
		App.display();
		std::cout << "f11\n";
	}
	return 0;
}
