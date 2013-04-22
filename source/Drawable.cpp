#include "Drawable.h"
//
// Constructor
Drawable::Drawable(sf::Sprite sprite, std::shared_ptr<Coordinates> coordinates) : m_sprite(sprite), m_coordinates(coordinates)
{
    m_width = m_sprite.getGlobalBounds().width;
    m_height = m_sprite.getGlobalBounds().height;
    std::cout << "Creating Drawable" << std::endl;
    std::cout << "Width: " << m_width << " Height: " << m_height << std::endl;
}
//
// Draw sprite on window
void Drawable::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
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
    m_width = m_sprite.getGlobalBounds().width;
    m_height = m_sprite.getGlobalBounds().height;
}
