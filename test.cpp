    #include "windowutils.hpp"
    #include <SFML/Graphics.hpp>
    #include <memory>
    #include <iostream>

    unsigned int R = 0 , G = 0 , B =0;

    using namespace std;
    using namespace sf;



    int main()
{
    TitleButtonsShape TBS;
/// sf::Event event;
    Event event;
    auto testwindow = BlackNiceWindow(500 , 200 ,"First test of swug");


    bool shouldClose = false;
    bool shouldHide = false;





    R = 100;
    G = 0;
    B = 254;
    while(testwindow->isOpen())
    {
        while(testwindow->pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                testwindow->close();
            }

             TBS.HandleMouseEvents(*testwindow, event, shouldClose, shouldHide);

        }
///     Hide window

        if(shouldClose)
        return 0;

        
        if (shouldHide)
        {
            testwindow->setVisible(false);
            shouldHide = false; // Reset hide flag
        }

        testwindow->clear(Color(R , G , B));
        TBS.DrawWindowTitleButtons(*testwindow);
        testwindow->display();

    }


    return 0;

}
