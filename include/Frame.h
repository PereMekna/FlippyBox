#ifndef FRAME_H
#define FRAME_H

#include <memory>
#include <SFML\Graphics.hpp>

class Frame
{
    public:
        Frame();
        Frame(std::shared_ptr<sf::Texture> newTexture, const sf::Rect<int>& newRect, const sf::Color& newColor = sf::Color::White);
        Frame(std::shared_ptr<sf::Texture> newTexture, const sf::Color& newColor = sf::Color::White);
        Frame(const Frame& Cpy);
        ~Frame();

        std::shared_ptr<sf::Texture> texture;
        sf::Rect<int> rect;
        sf::Color color;

};

#endif // FRAME_H
