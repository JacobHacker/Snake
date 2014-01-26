#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <cstdint>

class Vector2i;

enum class FoodType{
	NULL,
	NORMAL,
	BAD
};

struct Food{
	sf::Vector2i pos;
	FoodType foodType;
	uint64_t creationTime;
};

class FoodManager{
	public:
		FoodManager();
		std::size_t size(){return m_foodList.size();}
		Food &operator[](int i);

		void CreateFood(const Vector2i &pos, FoodType ft);
		void CreateRandomFood();

	private:
		std::vector<Food> m_foodList;
		int m_badFoodPerc;
};

#endif /*FOOD_H*/