    #pragma once


/// SFML
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>

/// X11
    #include <X11/Xlib.h>

/// Standrad
    #include <memory>
    #include <vector>
    #include <iostream>
    #include <cmath>
    using namespace sf;
    using namespace std;

    /*void MinimizeInWindow(sf::RenderWindow& window);*/
    
    void MinimizeWindowX11(sf::RenderWindow& window);       

   /// bool Tux = false , Win = false;

/// BlackNice
    unique_ptr<RenderWindow> BlackNiceWindow(unsigned int width , unsigned int height , const string WindowTitle );

/// Class for Title Bar -> Button's action , event 
    class TitleButtonsShape
{
    public:

///     Constructor
        TitleButtonsShape();
        
        void DrawWindowTitleButtons(sf::RenderWindow& window);

        void HandleWindowUtilsMouseEvents(sf::RenderWindow& window, sf::Event& event, bool& closeWindow, bool& hideWindow);

    private:

        bool AltDragIsUsed = false;
        sf::Vector2i GrabAmount;

        sf::CircleShape CloseButtonC;
        sf::CircleShape HideButtonC;
        std::vector<sf::CircleShape> ButtonShapes;


};
