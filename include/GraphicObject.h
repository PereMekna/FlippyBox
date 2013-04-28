/*

    GraphicObject.h
    Provide base class for graphic objects.
    Abstract.

*/
// TODO graphic object
// TODO Create new class for text
// TODO Modify animation
#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include <memory>
#include <SFML\Graphics.hpp>

#include "Coordinates.h"

class GraphicObject : public sf::Drawable, public sf::Transformable
{
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void update_position();
        ~GraphicObject(){}

    protected:
        template<class D> // type erasure
        explicit GraphicObject(std::shared_ptr<D> derivate, std::shared_ptr<Coordinates> coordinates) :
            sf::Drawable(),
            sf::Transformable(*derivate),
            m_drawable(derivate),
            m_coordinates(coordinates)
        {}

    private:
        std::shared_ptr<sf::Drawable> m_drawable;
        std::shared_ptr<Coordinates> m_coordinates;

        GraphicObject(const GraphicObject&);
        GraphicObject& operator=(const GraphicObject&);
};

#endif
