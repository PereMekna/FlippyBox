#include "Player.h"

Player::Player(sf::Sprite& sprite, std::shared_ptr<Coordinates> coor) : Drawable(sprite, coor)
{
    std::cout << "Creating Player" << std::endl;
}
