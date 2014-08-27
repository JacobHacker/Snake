#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "map.h"
#include "tile.h"
#include "snake.h"
#include "food.h"

#define DEBUG_WINDOW = true;

constexpr float pixelToScale( float imgSize, const int &size ){
	return ( 1 / imgSize ) * size;
}

const int TILE_SIZE = 16;

int main(){
	sf::RenderWindow App( sf::VideoMode( 800, 600, 32 ), "Snake" );
	App.setFramerateLimit( 30 );
	
	sf::Texture snakeTex;
	if( !snakeTex.loadFromFile( "img/Silver.png" ) ){
		return -1;
	}
	snakeTex.setSmooth( false );
	
	FoodManager foodManager;
	foodManager.setBadFoodPerc( 10 );
	foodManager.setFoodGenTime( sf::seconds( 15 ) );

	// Mighty snake warrior
	Snake snake(&foodManager);
	const float s = pixelToScale( snakeTex.getSize().x, TILE_SIZE );
	snake.setScale( {s, s} );
	snake.setSquareSize( TILE_SIZE );
	snake.createSprite( snakeTex );
	snake.reset( 10 );
	snake.setSpeed( 5 );

	while( App.isOpen() ){
		sf::Event event;
		while( App.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				App.close();
			}
			
			snake.pollEvent( &event );
		}
		
		// Logic
		foodManager.logic();
		snake.logic();
		
		// Render
		App.clear( sf::Color(255, 255, 255) );
		//map.render( &App );
		foodManager.render( &App );
		snake.render( &App );
		
		App.display();
	}
	return 0;
}
