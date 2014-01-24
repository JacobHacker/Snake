#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <cstdint>

enum class FoodType{
	NULL,
	NORMAL,
	BAD
};

struct Food{
	int x, y;
	FoodType foodType;
	uint64_t creationTime;
};

class FoodManager{
	public:
		size_t size(){return m_foodList.size();} const;
		int &operator[](int i);
	private:
		std::vector<Food> m_foodList;
};

#endif /*FOOD_H*/