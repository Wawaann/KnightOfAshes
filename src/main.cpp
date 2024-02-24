#include "include/global.hpp"
#include "include/mapManager.hpp"
#include "include/camera.hpp"

int main()
{
    sf::Event event;

    Background background = Background();

    sf::VideoMode video_mode = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Knight of Ahes", sf::Style::Close);

    sf::View view(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

    Player player = Player();

    window.setFramerateLimit(FPS);

    window.setVerticalSyncEnabled(true);

    window.setPosition(sf::Vector2i((video_mode.width / 2) - (SCREEN_WIDTH / 2), (video_mode.height / 2) - (SCREEN_HEIGHT / 2)));

    std::unique_ptr<MapManager> map = std::make_unique<MapManager>();

    map->loadMap(player);

    Camera camera = Camera(window, player.getPosition());

    while (window.isOpen())
    {
        int view_x;
        int prev_view_x;
        unsigned view_y;

        eventListener(window, event);

        player.update();

        window.clear();

        view_x = std::clamp<int>(round(player.getPosition().x) - 0.5f * (SCREEN_WIDTH - TILE_SIZE), 0, TILE_SIZE * map->get_map_sketch_width() - SCREEN_WIDTH);
        view_y = std::clamp<int>(round(player.getPosition().y) - 0.7f * (SCREEN_HEIGHT - TILE_SIZE), 0, TILE_SIZE * map->get_map_sketch_height() - SCREEN_HEIGHT);
 
        background.update(view_x, view_y, prev_view_x);

        camera.update(window, view_x, view_y);

        background.draw(window);

        map->drawMap(window);

        player.draw(window);

        window.display();

        prev_view_x = view_x;
    }
    return 0;
}