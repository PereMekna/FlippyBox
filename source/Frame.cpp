#include "Frame.h"

// Par copie
Frame::Frame(const Frame& Cpy)
{
    texture = Cpy.texture;
    rect = Cpy.rect;
    color = Cpy.color;
}

// Texture et Rect
Frame::Frame(std::shared_ptr<sf::Texture> newTexture, const sf::Rect<int>& newRect, const sf::Color& newColor)
{
    texture = newTexture;
    rect = newRect;
    color = newColor;
}

// Texture (Le Rect est au dimension de l'Texture)
Frame::Frame(std::shared_ptr<sf::Texture> newTexture, const sf::Color& newColor)
{
    texture = newTexture;
    if (texture != NULL)
        rect = sf::Rect<int>(0, 0, texture->getSize().x, texture->getSize().y);

    color = newColor;
}

// destructeur
Frame::~Frame()
{

}
