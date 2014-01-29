#include <iostream>
#include <cassert>
#include <stdexcept>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "food.h"

FoodManager::FoodManager()
	:m_badFoodPerc(20){
	m_rng.seed(std::random_device()());
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
	std::uniform_int_distribution<std::mt19937::result_type> fDist(1, 2);

	FoodType foodType;
	switch(fDist(m_rng)){
		case 1:
			foodType = FoodType::Normal;
			break;
		case 2:
			foodType = FoodType::Bad;
			break;
		default:
			throw std::out_of_range("Food type out of range");
	}

	std::uniform_int_distribution<std::mt19937::result_type> posDist(m_app->getSize().x, m_app->getSize().y);
}

void FoodManager::logic(){
	assert(m_foodGenTime > sf::Time::Zero);

	if(m_foodGenClock.getElapsedTime() >= m_foodGenTime){
		m_foodGenClock.restart();
		createRandomFood();
	}
}

void FoodManager::render(sf::RenderWindow *app){

}