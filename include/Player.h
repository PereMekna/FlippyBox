/*

    Player.h
    Provide player class.
    Derivated from Drawable and Collidable

*/
#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "FixedDrawable.h"
#include "Coordinates.h"

class Player : public FixedDrawable
{
    public:
        Player(sf::Sprite& sprite, std::shared_ptr<Coordinates> coor);
        ~Player(){}

    private:
        Player(const Player&);                                                      // Non copiable
        Player& operator=(const Player&);                                           // Non copiable
};

#endif
