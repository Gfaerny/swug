    #include "nowtime.hpp"

/// First adding x11 or window header for hiding window or minimize function
    #ifdef __linux__
    
        #include <X11/Xlib.h>

/// Undefine None macro in X11.h file that make use can't use sf::Style::None for window style
        #ifdef None
            
            #undef None
        #endif
    
    #elif __WIN32
        
        #include <window.h>

    #endif


    #include <SFML/Graphics.hpp>
    #include "windowutils.hpp"
    #include <SFML/Window.hpp>
    #include <ctime>

    /// Standard
    #include <memory>
    #include <vector>
    #include <iostream>
    #include <cmath>
    #include <climits>
    #include <cstring>

    using namespace std;
    using namespace sf;
 
/// Minimize window for windows system
    /*void MinimizeInWindow(sf::RenderWindow& window)
    {
        HWND hwnd = window.getSystemHandle();
        ShowWindow(hwnd, SW_MINIMIZE);

    }
    */


/// Minimize Window with x11 for linux 
void MinimizeWindowX11(sf::RenderWindow& window)
{
    ::Window x11Window = window.getSystemHandle();
    Display* display = XOpenDisplay(NULL);
    
    if (display)
    {
        int screen = DefaultScreen(display);
        XIconifyWindow(display, x11Window, screen);
        XFlush(display);
        XCloseDisplay(display);
    }
}

    

/// Making not resize able , not moving able and without any topbar button Black Window 
    unique_ptr<RenderWindow> BlackNiceWindow(unsigned int width , unsigned int height , const string WindowTitle )
    {
        return make_unique<RenderWindow>(VideoMode(width, height), WindowTitle, sf::Style::None);
    }
    


/// For class
/// Title Buttons and Title Buttons event all goes to this class

    TitleButtonsShape::TitleButtonsShape() 
    :   CloseButtonC(6) , HideButtonC(6)
    {
        CloseButtonC.setPosition(10, 10);
        CloseButtonC.setFillColor(Color::Red);
        ButtonShapes.push_back(CloseButtonC);

        HideButtonC.setPosition(30, 10);
        HideButtonC.setFillColor(Color::Yellow);
        ButtonShapes.push_back(HideButtonC);

    }
    void TitleButtonsShape::HandleWindowUtilsMouseEvents(sf::RenderWindow& window, sf::Event& event, bool& closeWindow, bool& hideWindow)
    {

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            Vector2f mousePos = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

///         If we click the Close button
            if (CloseButtonC.getGlobalBounds().contains(mousePos))
            {
                window.close();
                closeWindow = true;
                /* MASSAGE && TIME */
                
                std::cout << "swug_windowutils : Window get closed.Massage time : " <<  std::endl;
                NowTimeSwug();
            }

            ///         if we click the hide button
            else if (HideButtonC.getGlobalBounds().contains(mousePos))
            {
                
                ///window.setVisible(false);
                
                /*MASSAGE && TIME*/
                
                MinimizeWindowX11(window);

                std::cout << "swug_windowutils : Window get hided | Massage time : " <<  std::endl;
                ///hideWindow = true;
                NowTimeSwug();
            }

///         if we try to alt and drag window
///         grag gonna stated

            if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) 
            {

            AltDragIsUsed = true;
            GrabAmount = sf::Mouse::getPosition() - window.getPosition();
            }
            
            if (event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left) 
            {
                AltDragIsUsed = false;
            }
            
            if (event.type == sf::Event::MouseMoved && AltDragIsUsed) 
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition();
                window.setPosition(mousePos - GrabAmount);
            }


        }


    }

    void  TitleButtonsShape::DrawWindowTitleButtons(sf::RenderWindow & window)
    {

        for (auto& circle : ButtonShapes)
        {
            window.draw(circle);
        }    

    }








