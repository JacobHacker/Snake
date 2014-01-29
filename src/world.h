#ifndef WORLD_H
#define WORLD_H

class sf::Vector2i;

struct WorldSprite{
	sf::Sprite sprite;
	sf::Sprite scaledSprite;
	sf::Vector2i pos;
};

class World{
	public:
		render();
		void drawScaledTile();
		void drawTile();
};

#endif /*WORLD_H*/