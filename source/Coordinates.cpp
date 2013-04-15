#include "Coordinates.h"

Coordinates::Coordinates(int xx, int yy)
{
    if(xx <= 800) x = xx;
    else x = 0;

    if (yy <= 600) y = yy;
    else y = 0;
}

Coordinates::Coordinates(const Coordinates& coor) : x(coor.x), y(coor.y)
{}

bool operator==(const Coordinates& c1, const Coordinates& c2)
{
    if(c1 == c2) return true;
    else return false;
}

Coordinates& Coordinates::operator=(const Coordinates& coor)
{
    this->x = coor.x;
    this->y = coor.y;
    return *this;
}


