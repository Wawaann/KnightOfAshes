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

public:
    Background();
    ~Background();

    void setPosition(sf::Vector2f pos);
    void update(int i_view_x, unsigned i_view_y, int i_prev_view_x);
    void draw(sf::RenderWindow &window);
};
