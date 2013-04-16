#include "Player.h"

Player::Player(sf::Sprite& sprite, std::shared_ptr<Coordinates> coor) : FixedDrawable(sprite, coor)
{}
