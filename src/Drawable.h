#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable
{
    public:
        ~Drawable(){}
    protected:
        Drawable(sf::Sprite sprite);
        void setSprite();
    private:
        sf::Sprite m_sprite;

        Drawable(const Drawable&);              // Non copiable
        Drawable& operator=(const Drawable&);   // Non copiable
};

#endif
