#include "global.hpp"
#include "background.hpp"

class Camera
{
private:
    sf::View view;

public:
    Camera(sf::RenderWindow &window, sf::Vector2f ply_pos);
    ~Camera();

    void update(sf::RenderWindow &window, unsigned i_view_x, unsigned i_view_y);
};
