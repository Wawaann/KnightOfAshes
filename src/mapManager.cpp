#include "include/mapManager.hpp"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
    
}

unsigned short MapManager::get_map_sketch_height() const
{
    return this->map_sketch.getSize().y;
}

unsigned short MapManager::get_map_sketch_width() const
{
    return this->map_sketch.getSize().x;
}

void MapManager::loadMap(Player &player)
{
    map_sketch.loadFromFile("./assets/levels/level" + std::to_string(static_cast<unsigned short>(this->current_level)) + ".png");

    unsigned short map_height = this->get_map_sketch_height();
    unsigned short map_width = this->get_map_sketch_width();

    for (unsigned short i = 0; i < map_height; i++) {
        for (unsigned short j = 0; j < map_width; j++) {

            if (map_sketch.getPixel(j, i) == sf::Color(30, 30, 200)) {
                player.setPosition(j * TILE_SIZE, i * TILE_SIZE);
            }

            // (0, 0, 0)-> UNDERGROUND_0
            if (map_sketch.getPixel(j, i) == sf::Color(0, 0, 0)) {
                this->map.insert({std::make_tuple(j, i), Tile(UNDERGROUND_0, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * UNDERGROUND_0, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (5, 5, 5) -> UNDERGROUND_1
            else if (map_sketch.getPixel(j, i) == sf::Color(5, 5, 5)) {
                this->map.insert({std::make_tuple(j, i), Tile(UNDERGROUND_1, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * UNDERGROUND_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
            }
            // (10, 10, 10) -> UNDERGROUND_2
            else if (map_sketch.getPixel(j, i) == sf::Color(10, 10, 10)) {
                this->map.insert({std::make_tuple(j, i), Tile(UNDERGROUND_2, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * UNDERGROUND_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
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
            else if (map_sketch.getPixel(j, i) == sf::Color(165, 165, 165)) {
                this->map.insert({std::make_tuple(j, i), Tile(BORDER_2, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * BORDER_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
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
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_1, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
                else
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_1, sf::Vector2f(j * TILE_SIZE + TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_1, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), true, true)}); // reverse
            }
            // (180, 180, 180) -> STAIRS_2
            else if (map_sketch.getPixel(j, i) == sf::Color(180, 180, 180)) {
                if (this->map_sketch.getPixel(j + 1, i) == sf::Color(185, 185, 185))
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_2, sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), false, true)});
                else
                    this->map.insert({std::make_tuple(j, i), Tile(STAIRS_2, sf::Vector2f(j * TILE_SIZE + TILE_SIZE, i * TILE_SIZE), sf::IntRect(TILE_SIZE * STAIRS_2, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE), true, true)});
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

// A fix les sprite sont pas bon

void MapManager::drawMap(sf::RenderWindow &window)
{
    sf::Texture texture;
    texture.loadFromFile("./assets/tile.png");
    for (auto& [coord, tile] : this->map) {
        if (tile.cell == UNDERGROUND_0) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == UNDERGROUND_1) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == UNDERGROUND_2) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == GROUND_0) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == GROUND_1) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == GROUND_2) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == GROUND_3) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == EDGE_0) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            if (tile.is_reverse) {
                sprite.setScale(-1, 1);
            }
            window.draw(sprite);
        }
        else if (tile.cell == EDGE_1) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            if (tile.is_reverse) {
                sprite.setScale(-1, 1);
            }
            window.draw(sprite);
        }
        else if (tile.cell == EDGE_2) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            if (tile.is_reverse) {
                sprite.setScale(-1, 1);
            }
            window.draw(sprite);
        }
        else if (tile.cell == PLATFORM_0) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == PLATFORM_1) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == PLATFORM_2) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == PLATFORM_3) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == BORDER_0) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == BORDER_1) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            window.draw(sprite);
        }
        else if (tile.cell == BORDER_2) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            if (tile.is_reverse) {
                sprite.setScale(-1, 1);
            }
            window.draw(sprite);
        }
        else if (tile.cell == STAIRS_0) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            if (tile.is_reverse) {
                sprite.setScale(-1, 1);
            }
            window.draw(sprite);
        }
        else if (tile.cell == STAIRS_1) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            if (tile.is_reverse) {
                sprite.setScale(-1, 1);
            }
            window.draw(sprite);
        }
        else if (tile.cell == STAIRS_2) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            if (tile.is_reverse) {
                sprite.setScale(-1, 1);
            }
            window.draw(sprite);
        }
        else if (tile.cell == STAIRS_3) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(tile.pos);
            sprite.setTextureRect(tile.texture_rect);
            if (tile.is_reverse) {
                sprite.setScale(-1, 1);
            }
            window.draw(sprite);
        }
    }
}
