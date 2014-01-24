#include "food.h"

int &FoodManager::operator[](int i){
	return &m_foodList[i];
}