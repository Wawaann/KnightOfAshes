#include "global.hpp"

class Player
{
private:
    sf::RectangleShape player = sf::RectangleShape(sf::Vector2f(64, 128));
    sf::FloatRect player_hitbox;

    float vertical_speed;

public:
    Player();
    ~Player();

    void update(const std::vector<Tile> &i_map_ground_tile);
    void draw(sf::RenderWindow &i_window);
    void move(float i_x, float i_y);
    void setPosition(float i_x, float i_y);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
};