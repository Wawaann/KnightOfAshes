#include "include/global.hpp"

int eventListener(sf::RenderWindow &i_window, sf::Event &i_event)
{
    while (i_window.pollEvent(i_event))
    {
        if (i_event.type == sf::Event::Closed)
            i_window.close();
        if (i_event.type == sf::Event::KeyPressed)
        {
            if (i_event.key.code == sf::Keyboard::Escape)
                i_window.close();
        }
    }
    return 0;
}