/*

    Scene.h
    Handle all the drawables for drawing the scene.
    Only one Scene can be created.

*/
#ifndef SCENE_H
#define SCENE_H

#include<vector>
#include<memory>

#include <SFML\Graphics.hpp>

#include "Drawable.h"

class Scene
{
    public:
        explicit Scene(sf::RenderWindow& window);
        ~Scene(){};
        void add_drawable(std::unique_ptr<Drawable> drawable);
        void draw_all() const;
        void update_sprites();
    private:
        std::vector<std::unique_ptr<Drawable> > m_drawables;        // Every things that can be drawn
        sf::RenderWindow& m_window;

        Scene(const Scene&);                                        // Non copiable
        Scene& operator=(const Scene&);                             // Non copiable
};

#endif // SCENE_H
