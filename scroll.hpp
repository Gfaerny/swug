    #pragma once
    #include <SFML/Graphics.hpp>
    #include <vector>
    #include <iostream>

    using namespace sf;
    using namespace std;

    void ObjectSetScroll(vector<std::string> &ObjectsName , RenderWindow &window)

{
    Vector2u  WindowSize =  window.getSize();
    unsigned long long LastX = WindowSize.x  , LastY = WindowSize.y;

    std::cout << WindowSize.x << " " <<WindowSize.y << std::endl;
    for(string i : ObjectsName)
    {




    }





}