#include "global.hpp"

class Player
{
private:
    sf::RectangleShape player = sf::RectangleShape(sf::Vector2f(64, 128));

public:
    Player();
    ~Player();

    void update();
    void draw(sf::RenderWindow &window);
    void move(float x, float y);
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
};