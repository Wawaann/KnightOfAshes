#include "include/global.hpp"

int eventListener(sf::RenderWindow &window, sf::Event &event)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
        }
    }
    return 0;
}