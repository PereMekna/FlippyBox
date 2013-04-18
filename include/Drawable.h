/*

    Drawable.h
    Provide base class for graphic objects.
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
        void draw(sf::RenderWindow& window) const;
        void update_position();
        void set_sprite(sf::Sprite sprite);

        ~Drawable(){}

    protected:
        explicit Drawable(sf::Sprite sprite, std::shared_ptr<Coordinates> coordinates);

    private:
        sf::Sprite m_sprite;
        std::shared_ptr<Coordinates> m_coordinates;

        Drawable(const Drawable&);
        Drawable& operator=(const Drawable&);
};

#endif
