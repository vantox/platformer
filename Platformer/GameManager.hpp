//
//  GameManager.hpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

enum GameState
{
    menu = 0, //zamiast średników stosuje się przecinki
    game = 1
};

class Board;
class Menu;

class GameManager{
private:
    GameState gameState;
    sf::RenderWindow* mainWindow;
    sf::View* mainView;
    sf::Image* icon;
    Menu* menu;
    Board* board;
    static GameManager* instance;
    GameManager();
    
    
public:
    static GameManager* get();
    void startGame();
    
};

#endif /* GameManager_hpp */
