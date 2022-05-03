#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Engine.h"

Engine::Engine(sf::Vector2f& sizeOfWindow) : m_sizeOfWindow {sizeOfWindow} {    
    m_timePerFrame = sf::seconds(1.f/60); // 60 fps
}

Engine::~Engine() {
}

void Engine::update(sf::Time& elapsed) {
    while (elapsed > m_timePerFrame) {
        elapsed -= m_timePerFrame;
        m_update();
    }
}


void Engine::m_update() {
    sf::Vector2f currPos = m_shape.getPosition();

    float r = m_shape.getShape().getRadius();

    if (currPos.x < 1 || currPos.x >= m_sizeOfWindow.x - 2*r) {
        m_shape.changeDirectionToX();
    }

    if (currPos.y < 1 || currPos.y >= m_sizeOfWindow.y - 2*r) {
        m_shape.changeDirectionToY();
    }

    m_shape.move();
}

void Engine::draw(sf::RenderWindow& render) {
    render.clear();
    render.draw(m_shape.getShape());
    render.display();
}
