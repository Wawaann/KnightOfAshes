#ifndef GLOBAL_H
    #define GLOBAL_H

    //include all the necessary libraries
    #include <iostream>
    #include <memory>
    #include <string>
    #include <vector>
    #include <tuple>
    #include <cmath>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

    // for window
    constexpr unsigned short SCREEN_WIDTH = 1792;
    constexpr unsigned short SCREEN_HEIGHT = 896;
    constexpr unsigned short FPS = 60;

    //for map
    constexpr unsigned short TILE_SIZE = 128;

    //for player
    constexpr float MAX_VERTICAL_SPEED = 15;
    constexpr float GRAVITY = 0.35f;

    enum CELL
    {
        GROUND_0,
        GROUND_1,
        GROUND_2,
        GROUND_3,
        EDGE_0,
        EDGE_1,
        EDGE_2,
        PLATFORM_0,
        PLATFORM_1,
        PLATFORM_2,
        PLATFORM_3,
        STAIRS_0,
        STAIRS_1,
        STAIRS_2,
        STAIRS_3,
        BORDER_0,
        BORDER_1,
        BORDER_2,
        UNDERGROUND_0,
        UNDERGROUND_1,
        UNDERGROUND_2,
    };

    struct Tile
    {
        CELL            cell;
        sf::Vector2f    pos;
        sf::IntRect     texture_rect;
        sf::FloatRect   hitbox_rect;
        bool            is_reverse;
        bool            is_ground;

        Tile(CELL i_cell, sf::Vector2f i_pos, sf::IntRect i_texture_rect, sf::FloatRect i_hitbox_rect, bool i_is_reverse, bool i_is_ground) :
            cell(i_cell),
            pos(i_pos),
            texture_rect(i_texture_rect),
            hitbox_rect(i_hitbox_rect),
            is_reverse(i_is_reverse),
            is_ground(i_is_ground)
        {

        }
    };

    typedef std::map<std::tuple<int, int>, Tile> TileMap;

    //include functions
    int eventListener(sf::RenderWindow &i_window, sf::Event &i_event);

#endif