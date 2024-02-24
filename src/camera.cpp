#include "include/camera.hpp"

Camera::Camera(sf::RenderWindow &window, sf::Vector2f ply_pos)
{
    this->view.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    this->view.setCenter(ply_pos);
    window.setView(this->view);
}

Camera::~Camera()
{
}

void Camera::update(sf::RenderWindow &window, unsigned i_view_x, unsigned i_view_y)
{
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    //     background.moveSky(10, 0);
    //     background.moveTower(10, 0, 1, 0);
    //     background.moveTown(10, 0, 2, 0);
    //     background.moveMountain(10, 0, 3, 0);
    //     this->view.move(10, 0);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    //     background.moveSky(-10, 0);
    //     background.moveTower(-10, 0, -1, 0);
    //     background.moveTown(-10, 0, -2, 0);
    //     background.moveMountain(-10, 0, -3, 0);
    //     this->view.move(-10, 0);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    //     background.moveSky(0, -10);
    //     background.moveTower(0, -9.6, 0, 0);
    //     background.moveTown(0, -9.2, 0, 0);
    //     background.moveMountain(0, -9, 0, 0);
    //     this->view.move(0, -10);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    //     background.moveSky(0, 10);
    //     background.moveTower(0, 9.6, 0, 0);
    //     background.moveTown(0, 9.2, 0, 0);
    //     background.moveMountain(0, 9, 0, 0);
    //     this->view.move(0, 10);
    // }

    view.reset(sf::FloatRect(i_view_x, i_view_y, SCREEN_WIDTH, SCREEN_HEIGHT));
    window.setView(this->view);
}