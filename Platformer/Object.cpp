//
//  Object.cpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#include "Object.hpp"


Object::Object(sf::Vector2f position){
    idleTexture = nullptr;
    jumpTexture = nullptr;
    idleSprite = nullptr;
    jumpSprite = nullptr;
    isJumping = false;
    isMoving  = false;
    this->position = position;
}

void Object::draw(sf::RenderWindow* window){
    
    if (isJumping) {
        window->draw(*jumpSprite);
        jumpSprite->setPosition(position);
    }else {
        if (isMoving && direction == Direction::Right) {
            window->draw(*movementSprite[movementFrame]);
            movementSprite[movementFrame]->setPosition(position);
        }else
        {
            window->draw(*idleSprite);
            idleSprite->setPosition(position);
        }
        
            
        
    }
}