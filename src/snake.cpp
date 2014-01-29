#include <iostream>
#include <SFML/Window.hpp>

#include "snake.h"
#include "typedefs.h"

void directionSay(int dir){
	if(dir == DIRECT_UP){
		std::cout << "Up\n";
	}else if(dir == DIRECT_DOWN){
		std::cout << "Down\n";
	}else if(dir == DIRECT_RIGHT){
		std::cout << "Right\n";
	}else if(dir == DIRECT_LEFT){
		std::cout << "Left\n";
	}
}

Snake::Snake(FoodManager *fm)
	: m_foodManager(fm){

}

void Snake::createSprite(const sf::Texture &tex){
	m_sprite.setTexture(tex);
	
	//m_squareSize = tex.getSize().x;
}

void Snake::reset(int i){
	m_direction = DIRECT_DOWN;

	int size;
	if(i < 0){
		size = 3;
	}else{
		size = i;
	}
	
	int oldSize = m_squaresVector.size();
	m_squaresVector.resize(size, {-m_squareSize, -m_squareSize});
	
	// Reset snake node positions up to the resize
	for(int i=0; i<oldSize; ++i){
		m_squaresVector[i] = {-m_squareSize, -m_squareSize};
	}
	m_squaresVector[0] = {320, 320};
}

sf::Sprite Snake::getSprite(){
	return m_sprite;
}

void Snake::setScale(sf::Vector2f scale){
	m_sprite.setScale(scale);
}

void Snake::setSpeed(int speed){
	m_speed = speed;
}

int Snake::getSpeed(){
	return m_speed;
}

void Snake::setSquareSize(int size){
	m_squareSize = size;
}

void Snake::pollEvent(sf::Event *event){
	// prevSquareDirect used to prevent the snake from turning back on itself
	if( event->type == sf::Event::KeyPressed){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) 
				&& m_prevSquareDirect != DIRECT_DOWN){
			m_direction = DIRECT_UP;
		}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
				&& m_prevSquareDirect != DIRECT_UP){
			m_direction = DIRECT_DOWN;
		}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
				&& m_prevSquareDirect != DIRECT_RIGHT){
			m_direction = DIRECT_LEFT;
		}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
				&& m_prevSquareDirect != DIRECT_LEFT){
			m_direction = DIRECT_RIGHT;
		}
	}
}

void Snake::logic(){
	if( m_clock.getElapsedTime().asSeconds()*60 > (60/m_speed) ){
		m_prevSquareDirect = m_direction;
		m_clock.restart();
		
		sf::Vector2<float> prev(m_squaresVector[0]);
		if(m_direction == DIRECT_UP){
			m_squaresVector[0].y -= m_squareSize;
		}else if(m_direction == DIRECT_DOWN){
			m_squaresVector[0].y += m_squareSize;
		}else if(m_direction == DIRECT_LEFT){
			m_squaresVector[0].x -= m_squareSize;
		}else if(m_direction == DIRECT_RIGHT){
			m_squaresVector[0].x += m_squareSize;
		}
	
		//shift all parts forward
		for(uint i=1; i<m_squaresVector.size(); i++){
			sf::Vector2<float> tmp( m_squaresVector[i] );
			m_squaresVector[i] = prev;
			prev = tmp;
		}
	}
		
	// Check for collisions with itself
	for(size_t i=1; i<m_squaresVector.size(); ++i){
		if(m_squaresVector[0] == m_squaresVector[i]){
			reset();
		}
	}
}

void Snake::render(sf::RenderWindow *app){
	for(auto &it: m_squaresVector){
		m_sprite.setPosition( it );
		app->draw(m_sprite);
	}

	/*for(auto &it: m_snakeNodePos){
		m_world.drawTile(m_sprite, it);
	}*/
}
