//
//  Player.hpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Object.hpp"
#include "Collidable.hpp"

class Player : public Object,public Collidable{
private:
    int jumpTime;
    int maxHp;
    int hp;
    sf::String name;
    
public:
    Player(sf::Vector2f position, std::string name);
    void update();
    void draw(sf::RenderWindow* window);
    void move(sf::Vector2f movement);
    void move(Collidable* object, sf::Vector2f movement);
    
};



#endif /* Player_hpp */
