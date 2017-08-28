/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: korney
 *
 * Created on 15 июля 2017 г., 18:56
 */

#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "Engine.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    sf::RenderWindow window(sf::VideoMode(500,500), "ScreenSaver");
    window.setFramerateLimit(60);
    
    Engine engine;
    sf::CircleShape& circle = engine.getShape();  
    
    sf::Clock clock;   
    sf::Time elapsed = sf::Time::Zero;
    const sf::Time TimePerFrame = sf::seconds(1.f/60); // 60fps        
    
    while(window.isOpen()){
        
        // Process event
        sf::Event event;
        while(window.pollEvent(event)){
            if ((event.type == sf::Event::Closed) ||
                (event.type == sf::Event::KeyPressed && 
                 event.key.code == sf::Keyboard::Escape))
                window.close();
        }
                
        elapsed += clock.restart();
                       
        // Update        
        while(elapsed > TimePerFrame){
            elapsed -= TimePerFrame;
            engine.update();
        }
          
        // Render
        window.clear();
        window.draw(circle);
        
        window.display();
    }
    
    return 0;
}

