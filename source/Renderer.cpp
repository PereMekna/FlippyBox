#include "Renderer.h"
//
// Constructor
sf::RenderWindow Renderer::m_window(sf::VideoMode(1024, 768), "FlippyBox");
Renderer::Renderer()
{
    std::cout << "Creating Renderer" << std::endl;
}
//
// Add a drawable to Renderer
void Renderer::add_drawable(std::string name, RendererLayer layer, std::shared_ptr<Drawable> drawable)
{
    std::cout << "Adding Drawable: " << name << std::endl;
    if(drawable) m_drawables.insert(std::make_pair(std::make_pair(name, layer), drawable));
}
//
// Delete a drawable from Renderer
void Renderer::delete_drawable(std::string name, RendererLayer layer)
{
    std::map<std::pair<std::string, RendererLayer>, std::shared_ptr<Drawable> >::iterator it = m_drawables.find(std::make_pair(name, layer));

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
int Renderer::get_number_drawables() const
{
    return m_drawables.size();
}
//
// Clear all Drawables from Renderer
void Renderer::clear_drawables()
{
    std::cout << "Deleting all Drawables " << std::endl;
    m_drawables.clear();
}
//
// Update position of all sprites in the Renderer
void Renderer::update_drawables()
{
    for(std::map<std::pair<std::string, RendererLayer>, std::shared_ptr<Drawable> >::const_iterator it = m_drawables.begin();
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

    draw_drawables(Renderer::RendererLayer::Background);
    draw_drawables(Renderer::RendererLayer::Box);
    draw_drawables(Renderer::RendererLayer::Hud);

    m_window.display();
}

void Renderer::draw_drawables(RendererLayer layer) const
{
    for(std::map<std::pair<std::string, RendererLayer>, std::shared_ptr<Drawable> >::const_iterator it = m_drawables.begin();
    it != m_drawables.end();
    ++it)
    {
        if((it->first).second == layer)
        m_window.draw(*(it->second));
    }
}
