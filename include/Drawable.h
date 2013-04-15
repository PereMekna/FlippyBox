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
        void draw_sprite(sf::RenderWindow& window){draw(window);}
    protected:
        explicit Drawable(sf::Sprite sprite);

    private:
        sf::Sprite m_sprite;
        virtual void draw(sf::RenderWindow& window) const{window.draw(m_sprite);} // NVI

        Drawable(const Drawable&);              // Non copiable
        Drawable& operator=(const Drawable&);   // Non copiable
};

#endif
