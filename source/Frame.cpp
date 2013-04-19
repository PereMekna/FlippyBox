#include "Frame.h"

// Par copie
Frame::Frame(const Frame& Cpy)
{
    Texture = Cpy.Texture;
    Rect = Cpy.Rect;
    Color = Cpy.Color;
}

// Texture et Rect
Frame::Frame(sf::Texture* NewTexture, const sf::Rect<int>& NewRect, const sf::Color& NewColor)
{
    Texture = NewTexture;
    Rect = NewRect;
    Color = NewColor;
}

// Texture (Le Rect est au dimension de l'Texture)
Frame::Frame(sf::Texture* NewTexture, const sf::Color& NewColor)
{
    Texture = NewTexture;
    if (Texture != NULL)
        Rect = sf::Rect<int>(0, 0, Texture->getSize().x, Texture->getSize().y);

    Color = NewColor;
}

// destructeur
Frame::~Frame()
{

}
