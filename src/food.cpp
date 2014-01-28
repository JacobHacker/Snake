#include <cassert>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "food.h"

FoodManager::FoodManager()
	:m_badFoodPerc(20){

}

Food &FoodManager::operator[](int i){
	return m_foodList[i];
}

void FoodManager::setBadFoodPerc(int perc){
	m_badFoodPerc = perc;
}

void FoodManager::setFoodGenTime(sf::Time time){
	m_foodGenTime = time;
}

void FoodManager::createFood(const Vector2i &pos, FoodType ft){

}

void FoodManager::createRandomFood(){

}

void FoodManager::logic(){
	assert(m_foodGenTime > sf::Time::Zero);

	if(m_foodGenClock.getElapsedTime() >= m_foodGenTime){
		m_foodGenClock.reset();
		createRandomFood();
	}
}

void FoodManager::render(sf::RenderWindow *app){

}