/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shape.h
 * Author: korney
 *
 * Created on 28 августа 2017 г., 17:55
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>


class Circle : public sf::Drawable {
public:
    Circle();
    const sf::Vector2f& getPosition() const;
    sf::CircleShape& getShape() const;
    void changeDirectionToX();
    void changeDirectionToY();    
    void move();
    virtual ~Circle();
private:
    void m_changeFillColor();
    sf::CircleShape *m_shape;
    sf::Vector2f *m_direction;
    bool m_isColorChange;
    virtual void draw(sf::RenderTarget& target, 
            sf::RenderStates states) const override;

};

#endif /* SHAPE_H */

