/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Engine.cpp
 * Author: korney
 * 
 * Created on 28 августа 2017 г., 18:14
 */

#include <SFML/Graphics/RenderTarget.hpp>

#include "Engine.h"

Engine::Engine(sf::Vector2f& sizeOfWindow) : m_sizeOfWindow {sizeOfWindow} {    
}

Engine::~Engine() {
}

sf::CircleShape& Engine::getShape() const{
    return m_shape.getShape();
}

void Engine::update(){
    sf::Vector2f currPosition = m_shape.getPosition();
    
    float radius = m_shape.getShape().getRadius();
    
    if (currPosition.x < 1  || currPosition.x >= m_sizeOfWindow.x - 2*radius){
        m_shape.changeDirectionToX();
    }
    
    if (currPosition.y < 1  || currPosition.y >= m_sizeOfWindow.y - 2*radius){
        m_shape.changeDirectionToY();
    }
    
    m_shape.move();
}