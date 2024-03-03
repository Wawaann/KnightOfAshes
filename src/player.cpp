#include "include/player.hpp"

bool collision(float i_y, float i_x, const std::vector<Tile> &i_map_ground_tile)
{
    for (auto &tile : i_map_ground_tile) {
        if (tile.hitbox_rect.intersects(sf::FloatRect(i_x, i_y, TILE_SIZE, TILE_SIZE))) {
            return true;
        }
    }
    return false;
}



Player::Player()
{
    this->player.setFillColor(sf::Color::Green);
    this-> player.setPosition(0, 0);
    this->vertical_speed = 0;
}

Player::~Player()
{
    std::cout << "Position: " << player.getPosition().x << " " << player.getPosition().y << std::endl;

    
    std::cout << "ceil_0: " << std::floor(player.getPosition().x / TILE_SIZE) * TILE_SIZE << " " << std::floor(player.getPosition().y / TILE_SIZE) * TILE_SIZE << std::endl;
    std::cout << "ceil_1: " << std::ceil(player.getPosition().x / TILE_SIZE) * TILE_SIZE << " " << std::floor(player.getPosition().y / TILE_SIZE) * TILE_SIZE << std::endl;
    std::cout << "ceil_2: " << std::floor(player.getPosition().x / TILE_SIZE) * TILE_SIZE << " " << std::ceil(player.getPosition().y / TILE_SIZE) * TILE_SIZE << std::endl;
    std::cout << "ceil_3: " << std::ceil(player.getPosition().x / TILE_SIZE) * TILE_SIZE << " " << std::ceil(player.getPosition().y / TILE_SIZE) * TILE_SIZE << std::endl;

    //std::cout << "FIN" << std::endl;
}

void Player::update(const std::vector<Tile> &i_map_ground_tile)
{
    sf::Vector2f current_pos = this->player.getPosition();
    int pos_x;
    int pos_y;
    float vertical_collision = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        pos_x = 10;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        pos_x = -10;
    }
    else {
        pos_x = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        pos_y = -10;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        pos_y = 10;
    }
    else {
        pos_y = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->vertical_speed = -8;
    }

    if (collision(current_pos.y + vertical_speed, current_pos.x, i_map_ground_tile)) {
        vertical_speed = 0;
    }
    else {
        pos_y = vertical_speed;
    }
    this->move(pos_x, pos_y);


    this->vertical_speed = std::min(this->vertical_speed + GRAVITY, MAX_VERTICAL_SPEED);


    this->player_hitbox = sf::FloatRect(player.getPosition().x + (player.getSize().x / 2) - (this->player_hitbox.width / 2), player.getPosition().y + player.getSize().y - player_hitbox.height, player.getSize().x / 2, player.getSize().y / 10);
}

void Player::draw(sf::RenderWindow &i_window)
{
    //draw player_hitbox
    i_window.draw(player);
    sf::RectangleShape hitbox = sf::RectangleShape(sf::Vector2f(player_hitbox.width, player_hitbox.height));
    hitbox.setPosition(player_hitbox.left, player_hitbox.top);
    hitbox.setFillColor(sf::Color::Red);
    i_window.draw(hitbox);
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
