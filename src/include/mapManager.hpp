#include "global.hpp"
#include "player.hpp"

class MapManager
{
private:
    sf::Image       map_sketch;
    unsigned short  current_level = 0;

    TileMap           map;
    std::vector<Tile> map_ground_tile;
    std::vector<Tile> map_decoration_tile;

public:
    MapManager();
    ~MapManager();

    void update();
    void loadMap(Player &i_player);
    void update_levelsketch(const unsigned short i_current_level);
    void drawMap(sf::RenderWindow &i_window);

    unsigned short get_map_sketch_height() const;
    unsigned short get_map_sketch_width() const;
    std::vector<Tile> get_map_ground_tile() const;
};
