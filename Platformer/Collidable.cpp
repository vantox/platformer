//
//  Collidable.cpp
//  Platformer
//
//  Created by Piotrek Kiełek on 15/01/16.
//  Copyright © 2016 Michał Kiełek. All rights reserved.
//

#include "Collidable.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameManager.hpp"
#include "Game.hpp"
#include "Object.hpp"

Collidable::Collidable(){
    hitbox = sf::FloatRect(0,0,0,0);
}
sf::FloatRect Collidable::getHitbox()
{
    return hitbox;
}

void  Collidable::setHitbox(sf::FloatRect hitbox)
{
    this->hitbox = hitbox;
}

bool Collidable::isCollidingWith(Collidable* object)
{
    if (hitbox.intersects(object->hitbox)) {
        return 1;
    }else
        return 0;
}















