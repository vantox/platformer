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

void Collidable::move(sf::Vector2f movement)
{
        for (Collidable* collidable: GameManager::get()->getGame()->getCollidables()) {
            move(collidable, movement);
        }
    
}

void Collidable::move(Collidable *object, sf::Vector2f movement)
{
    
    if (movement.x > 0 && movement.y == 0) {
        hitbox.left += movement.x;
        if(isCollidingWith(object)){
            hitbox.left = object->getHitbox().left - hitbox.width;
        }
    }
//    if (movement.x < 0 && movement.y == 0) {
//        hitbox.left -= movement.x;
//        if(isCollidingWith(object)){
//            hitbox.left = object->getHitbox().left + object->getHitbox().width;
//        }
//    }
}















