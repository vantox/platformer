//
//  Collidable.hpp
//  Platformer
//
//  Created by Piotrek Kiełek on 15/01/16.
//  Copyright © 2016 Michał Kiełek. All rights reserved.
//

#ifndef Collidable_hpp
#define Collidable_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>



class Collidable
{
protected:
    sf::FloatRect hitbox;
public:
    Collidable();
    sf::FloatRect getHitbox();
    void setHitbox(sf::FloatRect hitbox);
    bool isCollidingWith(Collidable* object);
    void move(sf::Vector2f movement);
    void move(Collidable* object, sf::Vector2f movement);
};



#endif /* Collidable_hpp */