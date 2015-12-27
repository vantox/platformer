//
//  Board.hpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include "GameManager.hpp"

class Board{
private:
    sf::Texture* background_texture;
    sf::Sprite* background;
    
public:
    Board();
    void draw(sf::RenderWindow* window);
    void update();
};

#endif /* Board_hpp */
