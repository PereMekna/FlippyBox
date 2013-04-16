/*

    FixedDrawable.h
    Provide base class for fixed graphic objects.
    Abstract.

*/
//TODO Fixed_drawable and Animated_drawable
//TODO Inherit from sf::Drawable
#ifndef FIXEDDRAWABLE_H
#define FIXEDDRAWABLE_H

#include <memory>
#include <SFML\Graphics.hpp>

#include "Coordinates.h"

class FixedDrawable
{
    public:
        void draw(sf::RenderWindow& window);
        void update_position();

        ~FixedDrawable(){}

    protected:
        explicit FixedDrawable(sf::Sprite& sprite, std::shared_ptr<Coordinates> coordinates);

    private:
        sf::Sprite& m_sprite;
        std::shared_ptr<Coordinates> m_coordinates;

        FixedDrawable(const FixedDrawable&);
        FixedDrawable& operator=(const FixedDrawable&);
};

#endif
