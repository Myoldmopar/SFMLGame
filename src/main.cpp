#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <config.hpp>
#include <utilities.hpp>

int main()
{
    Configuration c;
    sf::RenderWindow window(sf::VideoMode(c.initialWidth, c.initialHeight), "SFML works!");
    window.setTitle("Lee Game");

    unsigned int const squareSpriteSideLength = 300;

    sf::CircleShape shape1(100.f);
    shape1.setFillColor(sf::Color::Green);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("media/sounds/punch.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    sf::Event event{};
    sf::Texture texture;
    texture.loadFromFile("media/textures/dragonSheet.png");
    sf::IntRect rectSourceSprite(0, 0, squareSpriteSideLength, squareSpriteSideLength);
    sf::Sprite sprite(texture, rectSourceSprite);

    sf::Clock clock;

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
                    if (event.key.code == sf::Keyboard::Space) {
                        sound.play();
                    }
                    break;

                    // we don't process other types of events
                default:
                    break;
            }
        }

        // adjust which row of the sprite sheet we are on
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rectSourceSprite.top = squareSpriteSideLength*0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            rectSourceSprite.top = squareSpriteSideLength*1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            rectSourceSprite.top = squareSpriteSideLength*2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rectSourceSprite.top = squareSpriteSideLength*3;
        }

        // adjust which column we are on based on a timer - one column per second
        if (clock.getElapsedTime().asSeconds() > 0.5f) {
            if (rectSourceSprite.left >= squareSpriteSideLength * 2)
                rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += squareSpriteSideLength;
            clock.restart();
        }

        // then draw the appropriate region of the sprite sheet
        sprite.setTextureRect(rectSourceSprite);

        window.clear();
        //window.draw(shape1);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
