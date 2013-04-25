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
        enum RendererLayer{Background, Box, Hud};
        void add_drawable(std::string name, RendererLayer layer, std::shared_ptr<Drawable> drawable);
        void delete_drawable(std::string name, RendererLayer layer);
        int get_number_drawables() const;
        void clear_drawables();

        void draw_all() const;
        void update_drawables();

    private:
        void draw_drawables(RendererLayer layer) const;
        std::map<std::pair<std::string, RendererLayer>, std::shared_ptr<Drawable> > m_drawables;
        static sf::RenderWindow m_window;

        Renderer(const Renderer&);
        Renderer& operator=(const Renderer&);
};

#endif // Renderer_H
