#include "FixedDrawable.h"
//
// Constructor
FixedDrawable::FixedDrawable(sf::Sprite& sprite, std::shared_ptr<Coordinates> coordinates) : m_sprite(sprite), m_coordinates(coordinates)
{}
//
// Draw sprite on window
void FixedDrawable::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}
//
// Apply new coordinates to sprite
void FixedDrawable::update_position()
{
    m_sprite.setPosition(m_coordinates->x, m_coordinates->y);
}
