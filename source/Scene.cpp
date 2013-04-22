#include "Scene.h"
//
// Constructor
Scene::Scene(sf::RenderWindow& window) : m_window(window)
{
    std::cout << "Creating Scene" << std::endl;
}
//
// Add a drawable to Scene
void Scene::add_drawable(std::string name, std::shared_ptr<Drawable> drawable)
{
    std::cout << "Adding Drawable: " << name << std::endl;
    if(drawable) m_drawables.insert(std::make_pair(name, drawable));
}
//
// Delete a drawable from Scene
void Scene::delete_drawable(std::string name)
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
int Scene::get_number_drawables()
{
    return m_drawables.size();
}
//
// Clear all Drawables from Scene
void Scene::clear_drawable()
{
    std::cout << "Deleting all Drawables " << std::endl;
    m_drawables.clear();
}
//
// Update position of all sprites in the Scene
void Scene::update_position_sprites()
{
    for(std::map<std::string, std::shared_ptr<Drawable> >::const_iterator it = m_drawables.begin();
        it != m_drawables.end();
        ++it)
        {
            it->second->update_position();
        }
}
//
// Update position of all sprites in the Scene
void Scene::draw_all() const
{
    m_window.clear(sf::Color::White);

    for(std::map<std::string, std::shared_ptr<Drawable> >::const_iterator it = m_drawables.begin();
        it != m_drawables.end();
        ++it)
        {
            m_window.draw(*(it->second));
            //->draw(m_window);
        }

    m_window.display();
}
