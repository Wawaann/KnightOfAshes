#include "global.hpp"
#include "background.hpp"

class Camera
{
private:
    sf::View view;

public:
    Camera(sf::RenderWindow &i_window, sf::Vector2f i_player_pos);
    ~Camera();

    void update(sf::RenderWindow &i_window, unsigned i_view_x, unsigned i_view_y);
};
