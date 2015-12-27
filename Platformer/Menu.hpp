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

class Menu{
    
public:
    Menu();
    void draw(sf::RenderWindow* window);
    void update();
};


#endif /* Menu_hpp */
