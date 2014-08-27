#ifndef WORLD_H
#define WORLD_H

class sf::Sprite;

enum class ScaleType{
	Unscaled,
	ScaleToTile,
};

// This enum is used to index an array, tread lightly
enum class Layer{
	Invisible = 0,
	Map,
	Objects,
	LayerMax = Objects, // Used for getting the size of an enum, should be the
						// last obj in the enum
};

struct WorldSprite{
	sf::Sprite sprite;
	sf::Sprite scaledSprite;
	sf::Vector2i pos;
};

class World{
	public:
		World(sf::RenderWindow *app);

		WorldSprite &createWorldSprite(Layer layer, sf::Sprite sprite);
		void removeSprite(Layer layer, uint index);

		void drawScaledTile();
		void drawTile();
		void render();
	private:
		sf::RenderWindow *m_app;
		//std::vector< std::vector<WorldSprite> > m_worldLayers;
		std::vector<WorldSprite> m_worldLayers[(int)Layer::LayerMax];
};

#endif /*WORLD_H*/