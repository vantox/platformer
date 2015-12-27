//
//  Game.hpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "GameManager.hpp"

class Board;
class Player;

class Game{
private:
    Board* board;
    Player* player;
    
public:
    Game();
    void draw(sf::RenderWindow* window);
    void update();
};

#endif /* Game_hpp */
