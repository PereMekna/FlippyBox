/*

    Drawable.h
    Provide graphic objects.
    Abstract.

*/
#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <memory>
#include <SFML\Graphics.hpp>

#include "Coordinates.h"

class Drawable
{
    public:
        ~Drawable(){}
        void draw(sf::RenderWindow& window);
    protected:
        explicit Drawable(sf::Sprite sprite, std::shared_ptr<Coordinates> coordinates);

    private:
        sf::Sprite m_sprite;
        std::shared_ptr<Coordinates> m_coordinates;

        Drawable(const Drawable&);                                                      // Non copiable
        Drawable& operator=(const Drawable&);                                           // Non copiable
};

#endif
