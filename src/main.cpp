#include <iostream>
#include <cmath>
#include <sstream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <config.hpp>
#include <utilities.hpp>

int main()
{
    Configuration c;
    sf::RenderWindow window(sf::VideoMode(c.initialWidth, c.initialHeight), "SFML works!");
    window.setTitle("Lee Game");

    unsigned int const fullSpriteSquareSideLength = 16*4;
    unsigned int const spriteSquareBorderThickness = 1*4;
    float animateIntervalInSeconds = 0.5f;

    sf::CircleShape shape1(100.f);
    shape1.setFillColor(sf::Color::Green);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("media/sounds/punch.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    sf::Texture texture2;
    texture2.loadFromFile("media/textures/red_guy/SpriteSheet.png");
    sf::IntRect redGuyRectangle(
            spriteSquareBorderThickness,
            spriteSquareBorderThickness,
            fullSpriteSquareSideLength - 2*spriteSquareBorderThickness,
            fullSpriteSquareSideLength - 2*spriteSquareBorderThickness
    );
    sf::Sprite redGuySprite(texture2, redGuyRectangle);
    redGuySprite.setPosition(c.initialWidth / 2.0f, c.initialHeight / 2.0f);

    sf::Font font;
    font.loadFromFile("media/fonts/8bit_wonder/8BITWONDER.TTF");
    sf::Text text;
    text.setFont(font);
    text.setString("POW");
    text.setPosition(c.initialWidth * 2.0f / 3.0f, 10);
    text.setFillColor(sf::Color::Red);

    sf::Event event{};
    sf::Clock clock;
    sf::Clock powClock;
    bool showPow = false;
    float powTime = 1.0f;

    bool redGuyGoingUp = true;

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
                        if (!showPow) {
                            sound.play();
                            powClock.restart();
                            showPow = true;
                        }
                    }
                    break;

                    // we don't process other types of events
                default:
                    break;
            }
        }

        // adjust which row of the sprite sheet we are on
        auto const redGuyPosition = redGuySprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            redGuyRectangle.top = 0*fullSpriteSquareSideLength + spriteSquareBorderThickness;
            redGuySprite.move(0, 0.25);
            if ((redGuyPosition.y + fullSpriteSquareSideLength) > window.getSize().y) {
                redGuySprite.setPosition(redGuyPosition.x, window.getSize().y - fullSpriteSquareSideLength);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            redGuyRectangle.top = 1*fullSpriteSquareSideLength + spriteSquareBorderThickness;
            redGuySprite.move(float(-0.25), 0);
            if (redGuyPosition.x <= 0) {
                redGuySprite.setPosition(0, redGuyPosition.y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            redGuyRectangle.top = 2*fullSpriteSquareSideLength + spriteSquareBorderThickness;
            redGuySprite.move(0.25, 0);
            if ((redGuyPosition.x + fullSpriteSquareSideLength) > window.getSize().x) {
                redGuySprite.setPosition(window.getSize().x - fullSpriteSquareSideLength, redGuyPosition.y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            redGuyRectangle.top = 3*fullSpriteSquareSideLength + spriteSquareBorderThickness;
            redGuySprite.move(0, float(-0.25));
            if (redGuyPosition.y <= 0) {
                redGuySprite.setPosition(redGuyPosition.x, 0);
            }
        }

        // adjust which column we are on based on a timer - one column per second
        if (clock.getElapsedTime().asSeconds() > animateIntervalInSeconds) {
            if (redGuyRectangle.left == spriteSquareBorderThickness) {
                redGuyRectangle.left = 1*fullSpriteSquareSideLength + spriteSquareBorderThickness;
                redGuyGoingUp = true;
            } else if (redGuyRectangle.left == 1*fullSpriteSquareSideLength + spriteSquareBorderThickness) {
                if (redGuyGoingUp) {
                    redGuyRectangle.left = 2*fullSpriteSquareSideLength + spriteSquareBorderThickness;
                } else {
                    redGuyRectangle.left = spriteSquareBorderThickness;
                }
            } else if (redGuyRectangle.left == 2*fullSpriteSquareSideLength + spriteSquareBorderThickness) {
                redGuyRectangle.left = 1*fullSpriteSquareSideLength + spriteSquareBorderThickness;
                redGuyGoingUp = false;
            } else {
                // shouldn't be able to get here
            }

            clock.restart();
        }

        if (powClock.getElapsedTime().asSeconds() > powTime) {
            showPow = false;
        }

        // then draw the appropriate region of the sprite sheet
        redGuySprite.setTextureRect(redGuyRectangle);

        window.clear();

        if (showPow) {
            window.draw(text);
        }
        window.draw(redGuySprite);

        window.display();

    }

    return 0;
}
