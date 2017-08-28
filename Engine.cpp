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

Engine::Engine() {    
}

Engine::~Engine() {
}

sf::CircleShape& Engine::getShape() const{
    return m_shape.getShape();
}

void Engine::update(){
    sf::Vector2f currPosition = m_shape.getPosition();
    if (currPosition.x < 0  || currPosition.x > 480){
        m_shape.changeDirectionToX();
    }
    
    if (currPosition.y < 0  || currPosition.y > 480){
        m_shape.changeDirectionToY();
    }
    
    m_shape.move();
}