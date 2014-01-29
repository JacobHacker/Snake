#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <cstdint>
#include <random>

class Vector2i;
class sf::RenderWindow;
class sf::Time;
class sf::Clock;

enum class FoodType{
	Null,
	Normal,
	Bad
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

		void setBadFoodPerc(int perc);

		void setFoodGenTime(sf::Time time);

		void createFood(const Vector2i &pos, FoodType ft);
		void createRandomFood();

		void logic();
		void render(sf::RenderWindow *app);

	private:
		std::vector<Food> m_foodList;
		int m_badFoodPerc;
		std::mt19937 m_rng;

		sf::Time m_foodGenTime;
		sf::Clock m_foodGenClock;

		sf::RenderWindow *m_app;
};

#endif /*FOOD_H*/