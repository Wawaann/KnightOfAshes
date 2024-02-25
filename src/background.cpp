#include "include/background.hpp"

Background::Background()
{
    this->sky_texture.loadFromFile("./assets/backgrounds/sky.png");
    this->sky_texture.setRepeated(true);
    this->sky.setTexture(this->sky_texture);
    this->sky.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    this->sky.setPosition(0, 0);

    this->tower_texture.loadFromFile("./assets/backgrounds/tower.png");
    this->tower_texture.setRepeated(true);
    this->tower.setTexture(this->tower_texture);
    this->tower.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    this->tower.setPosition(0, 0);

    this->town_texture.loadFromFile("./assets/backgrounds/town.png");
    this->town_texture.setRepeated(true);
    this->town.setTexture(this->town_texture);
    this->town.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    this->town.setPosition(0, 0);

    this->mountain_texture.loadFromFile("./assets/backgrounds/mountain.png");
    this->mountain_texture.setRepeated(true);
    this->mountain.setTexture(this->mountain_texture);
    this->mountain.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, 1100));
    this->mountain.setPosition(0, 0);
}

Background::~Background()
{
}

void Background::setPosition(sf::Vector2f i_pos)
{
    this->sky.setPosition(i_pos);
    this->tower.setPosition(i_pos);
    this->town.setPosition(i_pos);
    this->mountain.setPosition(i_pos);
}

void Background::update(int i_view_x, int i_view_y, int i_prev_view_x, int i_prev_view_y)
{
    this->sky.setPosition(sf::Vector2f(i_view_x, i_view_y));
    this->tower.setPosition(sf::Vector2f(i_view_x, i_view_y));
    this->town.setPosition(sf::Vector2f(i_view_x, i_view_y));
    this->mountain.setPosition(sf::Vector2f(i_view_x, i_view_y));

    this->time = this->clock.getElapsedTime();
    this->seconds = this->time.asSeconds();

    if (this->seconds > 0.02) {
        if (i_prev_view_x - i_view_x < 0) {
            this->tower.setTextureRect(sf::IntRect(this->tower.getTextureRect().left + 1, this->tower.getTextureRect().top, SCREEN_WIDTH, SCREEN_HEIGHT));
            this->town.setTextureRect(sf::IntRect(this->town.getTextureRect().left + 3, this->town.getTextureRect().top, SCREEN_WIDTH, SCREEN_HEIGHT));
            this->mountain.setTextureRect(sf::IntRect(this->mountain.getTextureRect().left + 5, this->mountain.getTextureRect().top, SCREEN_WIDTH, SCREEN_HEIGHT));
        }
        else if (i_prev_view_x - i_view_x > 0) {
            this->tower.setTextureRect(sf::IntRect(this->tower.getTextureRect().left - 1, this->tower.getTextureRect().top, SCREEN_WIDTH, SCREEN_HEIGHT));
            this->town.setTextureRect(sf::IntRect(this->town.getTextureRect().left - 3, this->town.getTextureRect().top, SCREEN_WIDTH, SCREEN_HEIGHT));
            this->mountain.setTextureRect(sf::IntRect(this->mountain.getTextureRect().left - 5, this->mountain.getTextureRect().top, SCREEN_WIDTH, SCREEN_HEIGHT));
        }

        if (i_prev_view_y - i_view_y < 0) {
            this->tower.setTextureRect(sf::IntRect(this->tower.getTextureRect().left, this->tower.getTextureRect().top + 1, SCREEN_WIDTH, SCREEN_HEIGHT));
            this->town.setTextureRect(sf::IntRect(this->town.getTextureRect().left, this->town.getTextureRect().top + 2, SCREEN_WIDTH, SCREEN_HEIGHT));
            this->mountain.setTextureRect(sf::IntRect(this->mountain.getTextureRect().left, this->mountain.getTextureRect().top + 3, SCREEN_WIDTH, SCREEN_HEIGHT));
        }
        else if (i_prev_view_y - i_view_y > 0) {
            this->tower.setTextureRect(sf::IntRect(this->tower.getTextureRect().left, this->tower.getTextureRect().top - 1, SCREEN_WIDTH, SCREEN_HEIGHT));
            this->town.setTextureRect(sf::IntRect(this->town.getTextureRect().left, this->town.getTextureRect().top - 2, SCREEN_WIDTH, SCREEN_HEIGHT));
            this->mountain.setTextureRect(sf::IntRect(this->mountain.getTextureRect().left, this->mountain.getTextureRect().top - 3, SCREEN_WIDTH, SCREEN_HEIGHT));
        }
        this->clock.restart();
    }

    //std::cout << i_prev_view_x << " - " <<  i_view_x << " = " << i_prev_view_x - i_view_x << std::endl;

    // Ajouter un chrono pour que le ciel se déplace moins vite (a voir si ça fait pas des saccades)
    // this->sky.setTextureRect(sf::IntRect(this->sky.getTextureRect().left - 1, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}

void Background::draw(sf::RenderWindow &i_window)
{
    i_window.draw(this->sky);
    i_window.draw(this->tower);
    i_window.draw(this->town);
    i_window.draw(this->mountain);
}

// void Background::moveSky(float x, float y)
// {
//     this->sky.move(x, y);
// }

// void Background::moveTower(float sprite_x, float sprite_y, int texture_x, int texture_y)
// {
//     this->tower.move(sprite_x, sprite_y);
//     this->tower.setTextureRect(sf::IntRect(this->tower.getTextureRect().left + texture_x, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
// }

// void Background::moveTown(float sprite_x, float sprite_y, int texture_x, int texture_y)
// {
//     this->town.move(sprite_x, sprite_y);
//     this->town.setTextureRect(sf::IntRect(this->town.getTextureRect().left + texture_x, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
// }

// void Background::moveMountain(float sprite_x, float sprite_y, int texture_x, int texture_y)
// {
//     this->mountain.move(sprite_x, sprite_y);
//     this->mountain.setTextureRect(sf::IntRect(this->mountain.getTextureRect().left + texture_x, 0, SCREEN_WIDTH, 1100));
// }
