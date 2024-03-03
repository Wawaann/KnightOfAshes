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

    window.setMouseCursorVisible(false);

    window.setPosition(sf::Vector2i((video_mode.width / 2) - (SCREEN_WIDTH / 2), (video_mode.height / 2) - (SCREEN_HEIGHT / 2)));

    std::unique_ptr<MapManager> map = std::make_unique<MapManager>();

    map->loadMap(player);

    Camera camera = Camera(window, player.getPosition());

    while (window.isOpen())
    {
        int view_x;
        int prev_view_x;
        int view_y;
        int prev_view_y;

        eventListener(window, event);

        window.clear();

        sf::RectangleShape ceil_0 = sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        sf::RectangleShape ceil_1 = sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        sf::RectangleShape ceil_2 = sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        sf::RectangleShape ceil_3 = sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));

        ceil_0.setFillColor(sf::Color::Transparent);
        ceil_1.setFillColor(sf::Color::Transparent);
        ceil_2.setFillColor(sf::Color::Transparent);
        ceil_3.setFillColor(sf::Color::Transparent);

        ceil_0.setOutlineColor(sf::Color::Red);
        ceil_1.setOutlineColor(sf::Color::Blue);
        ceil_2.setOutlineColor(sf::Color::Green);
        ceil_3.setOutlineColor(sf::Color::Yellow);

        ceil_0.setOutlineThickness(1);
        ceil_1.setOutlineThickness(1);
        ceil_2.setOutlineThickness(1);
        ceil_3.setOutlineThickness(1);

        ceil_0.setPosition(std::floor(player.getPosition().x / TILE_SIZE) * TILE_SIZE, std::floor(player.getPosition().y / TILE_SIZE) * TILE_SIZE);
        ceil_1.setPosition(std::ceil(player.getPosition().x / TILE_SIZE) * TILE_SIZE, std::floor(player.getPosition().y / TILE_SIZE) * TILE_SIZE);
        ceil_2.setPosition(std::floor(player.getPosition().x / TILE_SIZE) * TILE_SIZE, std::ceil(player.getPosition().y / TILE_SIZE) * TILE_SIZE);
        ceil_3.setPosition(std::ceil(player.getPosition().x / TILE_SIZE) * TILE_SIZE, std::ceil(player.getPosition().y / TILE_SIZE) * TILE_SIZE);

        map->update();

        player.update(map->get_map_ground_tile());

        view_x = std::clamp<int>(round(player.getPosition().x) - 0.45f * (SCREEN_WIDTH - TILE_SIZE), 0, TILE_SIZE * map->get_map_sketch_width() - SCREEN_WIDTH);
        view_y = std::clamp<int>(round(player.getPosition().y) - 0.6f * (SCREEN_HEIGHT - TILE_SIZE), 0, TILE_SIZE * map->get_map_sketch_height() - SCREEN_HEIGHT);
 
        background.update(view_x, view_y, prev_view_x, prev_view_y);

        camera.update(window, view_x, view_y);

        background.draw(window);

        map->drawMap(window);

        player.draw(window);

        window.draw(ceil_0);
        window.draw(ceil_1);
        window.draw(ceil_2);
        window.draw(ceil_3);

        window.display();

        prev_view_x = view_x;
        prev_view_y = view_y;
    }
    return 0;
}