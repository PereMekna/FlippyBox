#include "Renderer.h"
//
// Constructor
Renderer::Renderer(sf::RenderWindow& window) : m_window(window)
{
    std::cout << "Creating Renderer" << std::endl;
}
//
// Add a drawable to Renderer
void Renderer::add_drawable(std::string name, std::shared_ptr<Drawable> drawable)
{
    std::cout << "Adding Drawable: " << name << std::endl;
    if(drawable) m_drawables.insert(std::make_pair(name, drawable));
}
//
// Delete a drawable from Renderer
void Renderer::delete_drawable(std::string name)
{
    std::map<std::string, std::shared_ptr<Drawable> >::iterator it = m_drawables.find(name);

    if(it == m_drawables.end()) // Not found
    {
        std::cout << "Cannot delete, drawable " << name << " doesn't exist" << std::endl;
    }
    else
    {
        std::cout << "Deleting Drawable: " << name << std::endl;
        m_drawables.erase(it);
    }
}
//
// Return number of drawables
int Renderer::get_number_drawables()
{
    return m_drawables.size();
}
//
// Clear all Drawables from Renderer
void Renderer::clear_drawable()
{
    std::cout << "Deleting all Drawables " << std::endl;
    m_drawables.clear();
}
//
// Update position of all sprites in the Renderer
void Renderer::update_position_sprites()
{
    for(std::map<std::string, std::shared_ptr<Drawable> >::const_iterator it = m_drawables.begin();
        it != m_drawables.end();
        ++it)
        {
            it->second->update_position();
        }
}
//
// Update position of all sprites in the Renderer
void Renderer::draw_all() const
{
    m_window.clear(sf::Color::White);

    for(std::map<std::string, std::shared_ptr<Drawable> >::const_iterator it = m_drawables.begin();
        it != m_drawables.end();
        ++it)
        {
            m_window.draw(*(it->second));
        }

    m_window.display();
}
