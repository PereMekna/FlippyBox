/*

    Player.h
    Provide player class.
    Derivated from GraphicObject and Collidable

*/
#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "GraphicObject.h"
#include "Coordinates.h"

class Player : public GraphicObject
{
    public:
        Player(std::shared_ptr<sf::Sprite> sprite, std::shared_ptr<Coordinates> coor);
        ~Player(){}

        void set_sprite(sf::Sprite& sprite){*m_sprite = sprite;}

    private:
        std::shared_ptr<sf::Sprite> m_sprite;
        Player(const Player&);                                                      // Non copiable
        Player& operator=(const Player&);                                           // Non copiable
};

#endif
