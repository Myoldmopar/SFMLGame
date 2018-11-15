#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <config.hpp>
#include <utilities.hpp>

int main()
{
    Configuration c;
    sf::RenderWindow window(sf::VideoMode(c.initialHeight, c.initialWidth), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("media/sounds/punch.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    sf::Event event{};

    while (window.isOpen()) {
        // while there are pending events...
        while (window.pollEvent(event)) {
            // check the type of the event...
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                    // window size changed
                case sf::Event::Resized:
                    std::cout << "new width: " << event.size.width << std::endl;
                    std::cout << "new height: " << event.size.height << std::endl;
                    break;

                    // key pressed
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        std::cout << "the escape key was pressed" << std::endl;
                        std::cout << "control:" << event.key.control << std::endl;
                        std::cout << "alt:" << event.key.alt << std::endl;
                        std::cout << "shift:" << event.key.shift << std::endl;
                        std::cout << "system:" << event.key.system << std::endl;
                    }
                    break;

                    // we don't process other types of events
                default:
                    break;
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
