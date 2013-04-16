#include "Scene.h"
//
// Constructor
Scene::Scene(sf::RenderWindow& window) : m_window(window)
{}
//
// Add a drawable to the Scene
void Scene::add_fixed_drawable(std::shared_ptr<FixedDrawable> drawable)
{
    if(drawable) m_fixed_drawables.push_back(drawable);
}
//
// Update position of all sprites in the Scene
void Scene::update_sprites()
{
    for(std::vector<std::shared_ptr<FixedDrawable> >::const_iterator it = m_fixed_drawables.begin();
        it != m_fixed_drawables.end();
        ++it)
        {
            (*it)->update_position();
        }
}
//
// Update position of all sprites in the Scene
void Scene::draw_all() const
{
    m_window.clear(sf::Color(sf::Color::White));
    for(std::vector<std::shared_ptr<FixedDrawable> >::const_iterator it = m_fixed_drawables.begin();
        it != m_fixed_drawables.end();
        ++it)
        {
            (*it)->draw(m_window);
        }
    m_window.display();
}
