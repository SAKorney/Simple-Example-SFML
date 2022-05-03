#ifndef ENGINE_H
#define ENGINE_H

#include "Shape.h"

class Engine {
public:
    Engine(sf::Vector2f& sizeOfWindow);
    Engine(const Engine& orig) = delete;
    void update(sf::Time& elapsed);
    void draw(sf::RenderWindow& render);
    virtual ~Engine();
private:
    void m_update();
    Circle m_shape;
    sf::Vector2f& m_sizeOfWindow;
    sf::Time m_timePerFrame;
};

#endif /* ENGINE_H */

