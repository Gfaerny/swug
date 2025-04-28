#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Click the Circle");

    sf::CircleShape circle(10.f);
    circle.setPosition(10.f, 10.f);
    circle.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                    if (circle.getGlobalBounds().contains(mousePos))
                    {
                        circle.setFillColor(sf::Color::Red);
                    }
                }
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
