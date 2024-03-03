#include "include/mapManager.hpp"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
    
}

void MapManager::loadMap(Player &i_player)
{
    map_sketch.loadFromFile("./assets/levels/level_sketch_" + std::to_string(static_cast<unsigned short>(this->current_level)) + ".png");

    unsigned short map_height = this->get_map_sketch_height();
    unsigned short map_width = this->get_map_sketch_width();

    for (unsigned short i = 0; i < map_height; i++) {
        for (unsigned short j = 0; j < map_width; j++) {

            if (map_sketch.getPixel(j, i) == sf::Color(30, 30, 200)) {
                i_player.setPosition(j * TILE_SIZE, i * TILE_SIZE);
            }

            // (0, 0, 0)-> UNDERGROUND_0
            if (map_sketch.getPixel(j, i) == sf::Color(0, 0, 0)) {
                this->map.insert({std::make_tuple(j, i), Tile(UNDERGROUND_0, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * UNDERGROUND_0, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, false)});
            }
            // (5, 5, 5) -> UNDERGROUND_1
            else if (map_sketch.getPixel(j, i) == sf::Color(5, 5, 5)) {
                this->map.insert({std::make_tuple(j, i), Tile(UNDERGROUND_1, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * UNDERGROUND_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, false)});
            }
            // (10, 10, 10) -> UNDERGROUND_2
            else if (map_sketch.getPixel(j, i) == sf::Color(10, 10, 10)) {
                this->map.insert({std::make_tuple(j, i), Tile(UNDERGROUND_2, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * UNDERGROUND_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, false)});
            }
            // (100, 100, 100) -> GROUND_0
            else if (map_sketch.getPixel(j, i) == sf::Color(100, 100, 100)) {
                this->map.insert({std::make_tuple(j, i), Tile(GROUND_0, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * GROUND_0, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (105, 105, 105) -> GROUND_1
            else if (map_sketch.getPixel(j, i) == sf::Color(105, 105, 105)) {
                this->map.insert({std::make_tuple(j, i), Tile(GROUND_1, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * GROUND_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (110, 110, 110) -> GROUND_2
            else if (map_sketch.getPixel(j, i) == sf::Color(110, 110, 110)) {
                this->map.insert({std::make_tuple(j, i), Tile(GROUND_2, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * GROUND_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (115, 115, 115) -> GROUND_3
            else if (map_sketch.getPixel(j, i) == sf::Color(115, 115, 115)) {
                this->map.insert({std::make_tuple(j, i), Tile(GROUND_3, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * GROUND_3, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (120, 120, 120) -> EDGE_0
            else if (map_sketch.getPixel(j, i) == sf::Color(120, 120, 120)) {
                if (this->map_sketch.getPixel(j - 1, i) == sf::Color(105, 105, 105))
                    this->map.insert({std::make_tuple(j, i), Tile(EDGE_0, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * EDGE_0, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
                else
                    this->map.insert({std::make_tuple(j, i), Tile(EDGE_0, sf::Vector2f(j * TILE_SIZE + TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * EDGE_0, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), true, true)}); // reverse
            }
            // (125, 125, 125) -> EDGE_1
            else if (map_sketch.getPixel(j, i) == sf::Color(125, 125, 125)) {
                this->map.insert({std::make_tuple(j, i), Tile(EDGE_1, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * EDGE_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (130, 130, 130) -> EDGE_2
            else if (map_sketch.getPixel(j, i) == sf::Color(130, 130, 130)) {
                this->map.insert({std::make_tuple(j, i), Tile(EDGE_2, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * EDGE_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (135, 135, 135) -> PLATFORM_0
            else if (map_sketch.getPixel(j, i) == sf::Color(135, 135, 135)) {
                this->map.insert({std::make_tuple(j, i), Tile(PLATFORM_0, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * PLATFORM_0, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (140, 140, 140) -> PLATFORM_1
            else if (map_sketch.getPixel(j, i) == sf::Color(140, 140, 140)) {
                this->map.insert({std::make_tuple(j, i), Tile(PLATFORM_1, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * PLATFORM_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (145, 145, 145) -> PLATFORM_2
            else if (map_sketch.getPixel(j, i) == sf::Color(145, 145, 145)) {
                this->map.insert({std::make_tuple(j, i), Tile(PLATFORM_2, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * PLATFORM_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (150, 150, 150) -> PLATFORM_3
            else if (map_sketch.getPixel(j, i) == sf::Color(150, 150, 150)) {
                this->map.insert({std::make_tuple(j, i), Tile(PLATFORM_3, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * PLATFORM_3, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (155, 155, 155) -> BORDER_0 : Right border
            else if (map_sketch.getPixel(j, i) == sf::Color(155, 155, 155)) {
                this->map.insert({std::make_tuple(j, i), Tile(BORDER_0, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * BORDER_0, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (160, 160, 160) -> BORDER_1 : Left border
            else if (map_sketch.getPixel(j, i) == sf::Color(160, 160, 160)) {
                this->map.insert({std::make_tuple(j, i), Tile(BORDER_1, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * BORDER_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (165, 165, 165) -> BORDER_2
            // AJouter la possibilité de le reverse idiot !
            else if (map_sketch.getPixel(j, i) == sf::Color(165, 165, 165)) {
                this->map.insert({std::make_tuple(j, i), Tile(BORDER_2, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * BORDER_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, false)});
            }
            // (170, 170, 170) -> STAIRS_0
            else if (map_sketch.getPixel(j, i) == sf::Color(170, 170, 170)) {
                if (this->map_sketch.getPixel(j + 1, i) == sf::Color(175, 175, 175))
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_0, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_0, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
                else
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_0, sf::Vector2f(j * TILE_SIZE + TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_0, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), true, true)}); // reverse
            }
            // (175, 175, 175) -> STAIRS_1
            else if (map_sketch.getPixel(j, i) == sf::Color(175, 175, 175)) {
                if (this->map_sketch.getPixel(j - 1, i) == sf::Color(170, 170, 170))
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_1, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, false)});
                else
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_1, sf::Vector2f(j * TILE_SIZE + TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), true, false)}); // reverse
            }
            // (180, 180, 180) -> STAIRS_2
            else if (map_sketch.getPixel(j, i) == sf::Color(180, 180, 180)) {
                if (this->map_sketch.getPixel(j + 1, i) == sf::Color(185, 185, 185))
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_2, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, false)});
                else
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_2, sf::Vector2f(j * TILE_SIZE + TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), true, false)});
            }
            // (185, 185, 185) -> STAIRS_3
            else if (map_sketch.getPixel(j, i) == sf::Color(185, 185, 185)) {
                if (this->map_sketch.getPixel(j - 1, i) == sf::Color(180, 180, 180))
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_3, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_3, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
                else
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_3, sf::Vector2f(j * TILE_SIZE + TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_3, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), true, true)});
            }
        }

    }
}

void MapManager::update_levelsketch(const unsigned short i_current_level)
{
    this->current_level = i_current_level;
}

void MapManager::update()
{
    for (auto& [coord, tile] : this->map) {
        if (tile.is_ground) {
            this->map_ground_tile.push_back(tile);
        }
    }
}

void MapManager::drawMap(sf::RenderWindow &i_window)
{
    sf::Texture texture;
    texture.loadFromFile("./assets/tile.png");

    sf::RectangleShape hitbox = sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::White);
    hitbox.setOutlineThickness(2);

    std::vector<CELL> revers_tile{EDGE_0, BORDER_2, STAIRS_0, STAIRS_1, STAIRS_2, STAIRS_3};

    for (auto& [coord, tile] : this->map) {
        hitbox.setPosition(tile.pos);

        sf::Sprite sprit;
        sprit.setTexture(texture);
        sprit.setPosition(tile.pos);
        sprit.setTextureRect(tile.texture_rect);

        if (std::find(revers_tile.begin(), revers_tile.end(), tile.cell) != revers_tile.end()) {
            if (tile.is_reverse) {
                sprit.setScale(-1, 1);
            }
        }
        else {
            if (tile.is_reverse) {
                sprit.setScale(-1, 1);
            }
        }

        i_window.draw(sprit);
        i_window.draw(hitbox);
    }
}

unsigned short MapManager::get_map_sketch_height() const
{
    return this->map_sketch.getSize().y;
}

unsigned short MapManager::get_map_sketch_width() const
{
    return this->map_sketch.getSize().x;
}

std::vector<Tile> MapManager::get_map_ground_tile() const
{
    return this->map_ground_tile;
}
