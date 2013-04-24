/*

    Renderer.h
    Handle all the drawables for drawing the Renderer.
    Only one Renderer can be created.

*/
#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <string>
#include<vector>
#include<memory>

#include <SFML\Graphics.hpp>

#include "Drawable.h"

class Renderer
{
    public:
        explicit Renderer();
        ~Renderer(){};

        void add_drawable(std::string name, std::shared_ptr<Drawable> drawable);
        void delete_drawable(std::string name);
        int get_number_drawables() const;
        void clear_drawable();

        void draw_all() const;
        void update_position_sprites();

    private:
        std::map<std::string, std::shared_ptr<Drawable> > m_drawables;
        static sf::RenderWindow m_window;

        Renderer(const Renderer&);
        Renderer& operator=(const Renderer&);
};

#endif // Renderer_H
