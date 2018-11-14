#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <utilities.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("media/sounds/punch.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();

    }

    return 0;
}
