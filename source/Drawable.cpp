#include "Drawable.h"
//
// Constructor
Drawable::Drawable(sf::Sprite sprite, std::shared_ptr<Coordinates> coordinates) : m_sprite(sprite), m_coordinates(coordinates)
{}
//
// Draw sprite on window
void Drawable::draw(sf::RenderWindow& window) const
{
    window.draw(m_sprite);
}
//
// Apply new coordinates to sprite
void Drawable::update_position()
{
    m_sprite.setPosition(m_coordinates->x, m_coordinates->y);
}
//
// Set new sprite
void Drawable::set_sprite(sf::Sprite sprite)
{
    m_sprite = sprite;
}
