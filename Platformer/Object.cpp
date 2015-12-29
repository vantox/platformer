//
//  Object.cpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#include "Object.hpp"


Object::Object(sf::Vector2f position){
    direction = Direction::Right;
    changedDirection = false;
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
        jumpSprite->setPosition(position);
        window->draw(*jumpSprite);
    }else if (isMoving ) {
        movementSprite[movementFrame]->setPosition(position);
        window->draw(*movementSprite[movementFrame]);
    }else {
        
        idleSprite->setPosition(position);
        window->draw(*idleSprite);
        
    }
        
            
        
    
}