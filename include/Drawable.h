/*

    Drawable.h
    Provide graphic objects.
    Abstract.

*/
#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML\Graphics.hpp>

class Drawable : public sf::Drawable
{
    public:
        ~Drawable(){}
    protected:
        Drawable(sf::Sprite sprite);
        Drawable(sf::RectangleShape);
        void setSprite();
    private:
        sf::Sprite m_sprite;
        sf::RectangleShape m_rectangleShape;

        Drawable(const Drawable&);              // Non copiable
        Drawable& operator=(const Drawable&);   // Non copiable
};

#endif
