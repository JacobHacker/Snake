#include "snake.h"

#include <iostream>
#include <SFML/Window.hpp>

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

void Snake::reset(int i){
	int size;
	if(i==-1){ 
		size = 3;
	}else{
		size = i;
	}
	
	m_squaresVector.erase (m_squaresVector.begin(),m_squaresVector.end());
	
	//   Place the squares off screen, so the head doesn't collide with them
	// in the beginning. Set the head to the proper start position
	for(int i=0; i<size; i++){
		m_squaresVector.push_back( sf::Vector2<float>(-m_squareSize, -m_squareSize) );
	}
	m_squaresVector[0].x = m_squaresVector[0].y = 320;
}

void Snake::setSprite(sf::Sprite sprite, int numberOfSquares){
	m_sprite = sprite;
	
	m_speed = 2;
	m_squareSize = sprite.GetSize().x;
	
	
	reset(numberOfSquares);
	
	m_direction = DIRECT_DOWN;
	m_clock.Reset();
}

sf::Sprite Snake::getSprite(){
	return m_sprite;
}

void Snake::pollEvent(sf::Event *event){
	// check key presses
	// prevSquareDirect used to prevent the snake from turning back on itself
	if( event->Type == sf::Event::KeyPressed){
		if(event->Key.Code == sf::Key::Up 
				&& m_prevSquareDirect != DIRECT_DOWN){
			m_direction = DIRECT_UP;
		}else if(event->Key.Code == sf::Key::Down 
				&& m_prevSquareDirect != DIRECT_UP){
			m_direction = DIRECT_DOWN;
		}else if(event->Key.Code == sf::Key::Left 
				&& m_prevSquareDirect != DIRECT_RIGHT){
			m_direction = DIRECT_LEFT;
		}else if(event->Key.Code == sf::Key::Right 
				&& m_prevSquareDirect != DIRECT_LEFT){
			m_direction = DIRECT_RIGHT;
		}
	}
}

void Snake::logic(){
	//log the previous location of the head before moving
	sf::Vector2<float> prev(m_squaresVector[0]);
	
	if( m_clock.GetElapsedTime()*60 > (60/m_speed) ){
		m_prevSquareDirect = m_direction;
		m_clock.Reset();
		
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
		for(int i=1; i<m_squaresVector.size(); i++){
			sf::Vector2<float> tmp( m_squaresVector[i] );
			m_squaresVector[i] = prev;
			prev = tmp;
		}
	}
		
	//check for collisions upon itself
	for(int i=1; i<m_squaresVector.size(); i++){
		if(m_squaresVector[0] == m_squaresVector[i]){
			reset();
		}
	}
	
	if(){
	
	}
}

void Snake::render(sf::RenderWindow *app){
	for(int i=0; i<m_squaresVector.size(); i++){
		m_sprite.SetPosition( m_squaresVector[i] );
		app->Draw(m_sprite);
	}
	
}

