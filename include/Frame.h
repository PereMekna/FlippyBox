#ifndef FRAME_H
#define FRAME_H

#include <SFML\Graphics.hpp>

class Frame
{
    public:
        Frame();
        Frame(sf::Texture* NewTexture, const sf::Rect<int>& NewRect, const sf::Color& NewColor = sf::Color::White);
        Frame(sf::Texture* NewTexture, const sf::Color& NewColor = sf::Color::White);
        Frame(const Frame& Cpy);
        virtual ~Frame();

        sf::Texture* Texture;
        sf::Rect<int> Rect;
        sf::Color Color;

};

#endif // FRAME_H
