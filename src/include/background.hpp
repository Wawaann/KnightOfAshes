#include "global.hpp"

class Background
{
private:
    sf::Texture sky_texture = sf::Texture();
    sf::Texture tower_texture = sf::Texture();
    sf::Texture town_texture = sf::Texture();
    sf::Texture mountain_texture = sf::Texture();
    sf::Sprite sky = sf::Sprite();
    sf::Sprite tower = sf::Sprite();
    sf::Sprite town = sf::Sprite();
    sf::Sprite mountain = sf::Sprite();
    sf::Clock clock = sf::Clock();
    sf::Time time;
    float seconds;

public:
    Background();
    ~Background();

    void setPosition(sf::Vector2f i_pos);
    void update(int i_view_x, int i_view_y, int i_prev_view_x, int i_prev_view_y);
    void draw(sf::RenderWindow &i_window);
};
