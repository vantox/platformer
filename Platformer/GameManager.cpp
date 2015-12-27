//
//  GameManager.cpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#include "GameManager.hpp"
#include "ResourcePath.hpp"

#include "Config.hpp"

#include "Board.hpp"
#include "Menu.hpp"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager(){
    gameState = GameState::menu;
    mainWindow = new sf::RenderWindow(sf::VideoMode(BOARD_WIDTH, BOARD_HEIGHT), "Platformer");
    mainView = new sf::View();
    board = new Board();
    menu = new Menu();
    icon = new sf::Image();
    if (!icon->loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    mainWindow->setIcon(icon->getSize().x, icon->getSize().y, icon->getPixelsPtr());
    
}

GameManager* GameManager::get(){
    if(!instance){
        instance = new GameManager();
    }
    return instance;
    
}

void GameManager::startGame(){
    mainWindow->setFramerateLimit(FRAME_LIMIT);
    while (mainWindow->isOpen())
    {
        // Process events
        sf::Event event;
        while (mainWindow->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                mainWindow->close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                if(gameState == GameState::game){
                    gameState = GameState::menu;
                }
                else if(gameState == GameState::menu){
                    mainWindow->close();
                }
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G) {
                gameState = GameState::game;
            }
        }
        
        // Clear screen
        mainWindow->clear();
        
        // Draw the sprite
        
        switch(gameState){
            case GameState::game:
                board->update();
                board->draw(mainWindow);
                break;
            case GameState::menu:
                menu->update();
                menu->draw(mainWindow);
                
        }
        
        
        
        // Update the window
        mainWindow->display();
    }
}

void GameManager::setGameState(GameState state){
    gameState = state;
}