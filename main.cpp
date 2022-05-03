#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "Engine.h"
using namespace std;

int main(int argc, char** argv) {

    sf::Vector2f sizeOfWindow(500, 500);
    sf::VideoMode videoMode(sizeOfWindow.x, sizeOfWindow.y);

    sf::RenderWindow window(videoMode, "ScreenSaver");
    window.setFramerateLimit(60);

    Engine engine(sizeOfWindow);

    sf::Clock clock;
    sf::Time elapsed = sf::Time::Zero;

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
        engine.update(elapsed);

        // Render
        engine.draw(window);
    }

    return 0;
}

