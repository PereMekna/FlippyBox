#include "GraphicObject.h"
//
// Draw sprite on window
void GraphicObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*m_drawable, states.transform *= getTransform());
}
//
// Apply new coordinates to sprite
void GraphicObject::update_position()
{
    this->setPosition(m_coordinates->x, m_coordinates->y);
}
