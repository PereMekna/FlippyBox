/*

    Scene.h
    Handle all the drawables for drawing the scene.
    Only one Scene can be created.

*/
#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <string>
#include<vector>
#include<memory>

#include <SFML\Graphics.hpp>

#include "Drawable.h"

class Scene
{
    public:
        explicit Scene(sf::RenderWindow& window);
        ~Scene(){};

        void add_drawable(std::string name, std::shared_ptr<Drawable> drawable);
        void delete_drawable(std::string name);
        void clear_drawable();

        void draw_all() const;
        void update_sprites();

    private:
        std::map<std::string, std::shared_ptr<Drawable> > m_drawables;
        sf::RenderWindow& m_window;

        Scene(const Scene&);
        Scene& operator=(const Scene&);
};

#endif // SCENE_H
