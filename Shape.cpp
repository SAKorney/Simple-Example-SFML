/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shape.cpp
 * Author: korney
 * 
 * Created on 28 августа 2017 г., 17:56
 */

#include <SFML/Graphics/RenderTarget.hpp>

#include "Shape.h"

Shape::Shape() : m_isColorChange { false }
{    
    m_shape = new sf::CircleShape(25);
    m_shape->setFillColor(sf::Color::White);
    m_shape->setPosition(50, 70);
    m_direction = new sf::Vector2f(5, 4);
}

Shape::~Shape() {
    delete m_shape;
    delete m_direction;
}

sf::CircleShape& Shape::getShape() const{
    return *m_shape;
}

const sf::Vector2f& Shape::getPosition() const{
    return m_shape->getPosition();
}

void Shape::changeDirectionToX(){
    m_direction-> x *= -1;
    m_changeFillColor();
}

void Shape::changeDirectionToY(){
    m_direction-> y *= -1;
    m_changeFillColor();
}

void Shape::m_changeFillColor(){
    m_isColorChange = !m_isColorChange;
    
    sf::Color fillColor = m_isColorChange ?
        sf::Color::Green : sf::Color::White;
    
    m_shape->setFillColor(fillColor);
}

void Shape::move(){
    m_shape-> move(*m_direction);
}

void Shape::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(*m_shape, states);
}