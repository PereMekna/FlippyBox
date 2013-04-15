#include "Scene.h"

Scene::Scene(sf::RenderWindow& window) : m_window(window)
{
    //ctor
}

void Scene::draw_all() const
{
    for(std::vector<std::unique_ptr<Drawable> >::const_iterator it = m_drawables.begin();
        it != m_drawables.end();
        ++it)
        {
            (*it)->draw_sprite(m_window);
        }
}
