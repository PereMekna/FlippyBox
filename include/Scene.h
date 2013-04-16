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

#include "FixedDrawable.h"

class Scene
{
    public:
        explicit Scene(sf::RenderWindow& window);
        ~Scene(){};

        void add_fixed_drawable(std::shared_ptr<FixedDrawable> drawable);
        void draw_all() const;
        void update_sprites();

    private:
        std::vector<std::shared_ptr<FixedDrawable> > m_fixed_drawables;
        sf::RenderWindow& m_window;

        Scene(const Scene&);
        Scene& operator=(const Scene&);
};

#endif // SCENE_H
