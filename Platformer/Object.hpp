//
//  Object.hpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include "GameManager.hpp"
#include <vector>

enum Direction{
    Left = 0,
    Right = 1
};

class Object{
protected:
    int movementFrame;
    int idleFrame;
    sf::Texture* idleTexture;
    //std::vector<sf::Texture*> movementTexture;
    sf::Texture* movementTexture;
    sf::Texture* jumpTexture;
    sf::Texture* jumpStartTexture;
    sf::Texture* fallingTexture;
    std::vector<sf::Sprite*> jumpStartSprite;
    std::vector<sf::Sprite*> movementSprite;
    std::vector<sf::Sprite*> idleSprite;
    sf::Sprite* jumpSprite;
    sf::Sprite* fallingSprite;
    
    bool isMoving;
    bool isJumping;
    bool changedDirection;
    Direction direction;
    sf::Vector2f position;
    
    
public:
    Object(sf::Vector2f position);
    
    virtual void draw(sf::RenderWindow* window);
    
};

#endif /* Object_hpp */
