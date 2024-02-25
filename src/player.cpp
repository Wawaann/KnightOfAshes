#include "include/player.hpp"

Player::Player()
{
    player.setFillColor(sf::Color::Green);
    player.setPosition(0, 0);
}

Player::~Player()
{
}

void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->move(10, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->move(-10, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->move(0, -10);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->move(0, 10);
    }
}

void Player::draw(sf::RenderWindow &i_window)
{
    i_window.draw(player);
}

void Player::move(float i_x, float i_y)
{
    player.move(i_x, i_y);
}

void Player::setPosition(float i_x, float i_y)
{
    player.setPosition(i_x, i_y);
}

sf::Vector2f Player::getPosition()
{
    return player.getPosition();
}

sf::Vector2f Player::getSize()
{
    return player.getSize();
}
