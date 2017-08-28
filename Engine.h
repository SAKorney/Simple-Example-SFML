/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Engine.h
 * Author: korney
 *
 * Created on 28 августа 2017 г., 18:14
 */

#ifndef ENGINE_H
#define ENGINE_H

#include "Shape.h"

class Engine {
public:
    Engine(sf::Vector2f& sizeOfWindow);
    Engine(const Engine& orig) = delete;
    void update();
    sf::CircleShape& getShape() const;
    virtual ~Engine();
private:
    Circle m_shape;
    sf::Vector2f& m_sizeOfWindow;
};

#endif /* ENGINE_H */

