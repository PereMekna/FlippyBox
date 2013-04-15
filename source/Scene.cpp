#include "Scene.h"

Scene::Scene(sf::RenderWindow& window) : m_window(window)
{}

void Scene::add_drawable(std::unique_ptr<Drawable> drawable)
{
    if(drawable) m_drawables.push_back(std::move(drawable));
}

void Scene::draw_all() const
{
    for(std::vector<std::unique_ptr<Drawable> >::const_iterator it = m_drawables.begin();
        it != m_drawables.end();
        ++it)
        {
            (*it)->draw(m_window);
        }
}
