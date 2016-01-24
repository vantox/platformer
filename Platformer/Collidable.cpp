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
    hitbox.left += movement.x;
    hitbox.top += movement.y;
    for (Collidable* collidable: GameManager::get()->getGame()->getCollidables()) {
        move(collidable, movement);
    }
    
}

void Collidable::move(Collidable *object, sf::Vector2f movement)
{
    
    if (movement.x > 0 && movement.y == 0) {
        //        hitbox.left += movement.x;
        if(isCollidingWith(object)){
            //            std::cout << "koliduje z hitboxem:"<< object->getHitbox().left << "  " << object->getHitbox().top << " " << object->getHitbox().width << " " << object->getHitbox().height << "\n";
            hitbox.left = object->getHitbox().left - hitbox.width;
            std::cout << "kolizja, hitbox left: "<<hitbox.left << "\n";
        }
    }
    else if (movement.x < 0 && movement.y == 0) {
        //        hitbox.left += movement.x;
        if(isCollidingWith(object)){
            //            std::cout << "koliduje z hitboxem:"<< object->getHitbox().left << "  " << object->getHitbox().top << " " << object->getHitbox().width << " " << object->getHitbox().height << "\n";
            hitbox.left = object->getHitbox().left + object->getHitbox().width;
        }
    }
    else if (movement.y > 0 && movement.x == 0) {
        if (isCollidingWith(object)) {
            hitbox.top = object->getHitbox().top - hitbox.height;
        }
    }
    else if (movement.y < 0 && movement.x == 0){
        if (isCollidingWith(object)) {
            hitbox.top = object->getHitbox().top + object->getHitbox().height;
        }
    }
    
    //std::cout << "hitbox left z move:"<< hitbox.left<< "\n";
    
    //position.x += hitbox.left - lastHitboxLeft;
}














