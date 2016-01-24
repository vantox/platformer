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
#include <vector>
#include "GameManager.hpp"

class Board;
class Player;
class Block;
class Collidable;

class Game{
private:
    Board* board;
    Player* player;
    Block* block;Block* block2;Block* block3;
    std::vector<Collidable*> collidables;
    
    
public:
    Game();
    void draw(sf::RenderWindow* window);
    void update();
    std::vector<Collidable*>& getCollidables();
    void addCollidable(Collidable* collidable);
};

#endif /* Game_hpp */
