#include <SFML/System/Vector2.hpp>

#include "food.h"

FoodManager::FoodManager(){
	m_badFoodPerc = 20; // 1 in 5
}

Food &FoodManager::operator[](int i){
	return m_foodList[i];
}

//void FoodManager::{}

void FoodManager::CreateFood(const Vector2i &pos, FoodType ft){

}

void FoodManager::CreateRandomFood(){

}