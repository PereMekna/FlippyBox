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

class Drawable : public sf::Drawable
{
    public:
        void update_position();
        void set_sprite(sf::Sprite sprite);

        ~Drawable(){}

    protected:
        explicit Drawable(sf::Sprite sprite, std::shared_ptr<Coordinates> coordinates);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Sprite m_sprite;
        int m_width;
        int m_height;
        std::shared_ptr<Coordinates> m_coordinates;

        Drawable(const Drawable&);
        Drawable& operator=(const Drawable&);
};

#endif
