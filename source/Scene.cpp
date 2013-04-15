#include "Scene.h"

Scene::Scene(sf::RenderWindow& window) : m_window(window)
{}

void Scene::add_drawable(std::shared_ptr<Drawable> drawable)
{
    if(drawable) m_drawables.push_back(drawable);
}

void Scene::update_sprites()
{
    for(std::vector<std::shared_ptr<Drawable> >::const_iterator it = m_drawables.begin();
        it != m_drawables.end();
        ++it)
        {
            (*it)->update_position();
        }
}

void Scene::draw_all() const
{
    m_window.clear();
    for(std::vector<std::shared_ptr<Drawable> >::const_iterator it = m_drawables.begin();
        it != m_drawables.end();
        ++it)
        {
            (*it)->draw(m_window);
        }
    m_window.display();
}
