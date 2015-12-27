//
//  Menu.hpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "GameManager.hpp"

enum MenuState
{
    newGame = 0,
    loadGame = 1,
    option = 2,
    Exit = 3
    
};

class Menu{
private:
    int toNextChange;
    sf::Font font;
    sf::Text text[4];
    MenuState state;
    
public:
    Menu();
    void draw(sf::RenderWindow* window);
    void update();
};


#endif /* Menu_hpp */
