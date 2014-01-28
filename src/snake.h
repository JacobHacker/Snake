#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

const int DIRECT_UP = 0;
const int DIRECT_DOWN = 1;
const int DIRECT_LEFT = 2;
const int DIRECT_RIGHT = 3;

class FoodManager;

class Snake{
	public:
		Snake(FoodManager *fm);
		
		void createSprite(const sf::Texture &sprite);
		sf::Sprite getSprite();
		void setScale(sf::Vector2f scale);

		void setSpeed(int speed);
		int getSpeed();

		void setSquareSize(int size);

		void pollEvent(sf::Event *event);
		void logic();
		void render(sf::RenderWindow *app);

		void reset(int size=-1);
	
	private:
		int m_speed;
		float m_squareSize;
		int m_prevSquareDirect;
		sf::Vector2f startPosition;
		sf::Rect<float> m_appRect;
		int m_direction;

		sf::Sprite m_sprite;
		std::vector< sf::Vector2<float> > m_squaresVector;
		sf::Clock m_clock;

		FoodManager *m_foodManager;
};

#endif
