#include "include/camera.hpp"

Camera::Camera(sf::RenderWindow &i_window, sf::Vector2f i_player_pos)
{
    this->view.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    this->view.setCenter(i_player_pos);
    i_window.setView(this->view);
}

Camera::~Camera()
{
}

void Camera::update(sf::RenderWindow &i_window, unsigned i_view_x, unsigned i_view_y)
{
    view.reset(sf::FloatRect(i_view_x, i_view_y, SCREEN_WIDTH, SCREEN_HEIGHT));
    i_window.setView(this->view);
}