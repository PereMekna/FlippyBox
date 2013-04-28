#include "Player.h"

Player::Player(std::shared_ptr<sf::Sprite> sprite, std::shared_ptr<Coordinates> coor):
    GraphicObject(sprite, coor),
    m_sprite(sprite)
{
    std::cout << "Creating Player" << std::endl;
}
