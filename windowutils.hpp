    #ifdef WINDOWUTILS_HPP
    #define WINDOWYTILS_HPP
    #endif
    #include <SFML/Graphics.hpp>
    #include <memory>
    #include <vector>
    #include <iostream>
    #include <cmath>
    using namespace sf;
    using namespace std;

    /// BlackNice
    unique_ptr<RenderWindow> BlackNiceWindow(unsigned int width , unsigned int height , const string WindowTitle )
    {
        return make_unique<RenderWindow>(VideoMode(width, height), WindowTitle, sf::Style::None);
    }


    class TitleButtonsShape
{
    public:

    TitleButtonsShape()
    : CloseButtonC(6), HideButtonC(6)
    {
        CloseButtonC.setPosition(10, 10);
        CloseButtonC.setFillColor(Color::Red);
        ButtonShapes.push_back(CloseButtonC);
        HideButtonC.setPosition(30, 10);
        HideButtonC.setFillColor(Color::Yellow);
        ButtonShapes.push_back(HideButtonC);
        /*
        /// close circle
        CircleShape CloseButtonC (6);
        CloseButtonC.setPosition( 10, 10);
        CloseButtonC.setFillColor(Color::Red);
        ButtonShapes.push_back(CloseButtonC);

        ///hide circle
        CircleShape HideButtonC (6);
        HideButtonC.setPosition( 30, 10);
        HideButtonC.setFillColor(Color::Yellow);
        ButtonShapes.push_back(HideButtonC);
*/
    }

     void DrawWindowTitleButtons(sf::RenderWindow& window)
     {
        for (auto& circle : ButtonShapes)
        {
            window.draw(circle);
        }
    }



  void HandleMouseEvents(sf::RenderWindow& window, sf::Event& event, bool& closeWindow, bool& hideWindow)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        Vector2f mousePos = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

        if (CloseButtonC.getGlobalBounds().contains(mousePos))
        {
            window.close();
            closeWindow = true;
            std::cout << "KARCARD RED BUTTONS AND WINDOW'S GET CLOSED" << std::endl;
        }
        else if (HideButtonC.getGlobalBounds().contains(mousePos))
        {
            window.setVisible(false);
            std::cout << "WINDOW'S GET HIDE SUCCESSFULLY" << std::endl;
            std::cout << mousePos.x << " " << mousePos.y << std::endl;
            hideWindow = true;
        }
    }
}


    private:

    sf::CircleShape CloseButtonC;
    sf::CircleShape HideButtonC;
    std::vector<sf::CircleShape> ButtonShapes;


};
