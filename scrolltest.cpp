#include <SFML/Graphics.hpp>
#include "windowutils.hpp"
#include "scroll.hpp"
using namespace std;
using namespace sf;

int main()
{
    TitleButtonsShape TBS;
    Event event;

    auto window = BlackNiceWindow(500, 300, "Test Scroll with Keyboard");

    sf::Text TextHi;
    sf::Text TextHi1;

    Font fontArial;
    if (!fontArial.loadFromFile("arial.ttf"))
    {
        std::cerr << "Error: font not loaded" << std::endl;
    }

    TextHi.setFont(fontArial);
    TextHi.setString("Hi");
    TextHi.setCharacterSize(200);
    TextHi.setPosition(10, 20);
    TextHi.setFillColor(sf::Color::White);

    TextHi1.setFont(fontArial);
    TextHi1.setString("Hi again!!");
    TextHi1.setCharacterSize(120);
    TextHi1.setPosition(10, 400);
    TextHi1.setFillColor(sf::Color::White);

    bool shouldClose = false, shouldHide = false;

    float scrollOffset = 0.0f;

    std::vector<std::string> mamad = {"mamad" , "mohamad"};

    ObjectSetScroll(mamad , *window);

    while (window->isOpen())
    {
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window->close();
            }

            TBS.HandleMouseEvents(*window, event, shouldClose, shouldHide);

            // 📜 اسکرول با کیبورد
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Down)
                {
                    scrollOffset += 20; // هر بار 20 پیکسل پایین‌تر
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    scrollOffset -= 20; // هر بار 20 پیکسل بالاتر
                    if (scrollOffset < 0) scrollOffset = 0; // از اول پنجره بالاتر نره
                }
            }
        }

        window->clear(Color::Black);


        // 📜 اعمال اسکرول روی متن
        sf::Text scrolledTextHi = TextHi;
        sf::Text scrolledTextHi1 = TextHi1;

        scrolledTextHi.move(0, -scrollOffset);
        scrolledTextHi1.move(0, -scrollOffset);

        window->draw(scrolledTextHi);
        window->draw(scrolledTextHi1);

        TBS.DrawWindowTitleButtons(*window);

        window->display();
    }

    return 0;
}
