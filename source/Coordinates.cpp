#include "Coordinates.h"

Coordinates::Coordinates(int x, int y)
{
    if(x <= 800) m_x = x;
    else m_x = 0;

    if (x <= 600) m_y = y;
    else m_y = 0;
}

Coordinates::Coordinates(const Coordinates& coor) : m_x(coor.m_x), m_y(coor.m_y)
{}

bool operator==(const Coordinates& c1, const Coordinates& c2)
{
    if(c1 == c2) return true;
    else return false;
}

Coordinates& Coordinates::operator=(const Coordinates& coor)
{
    this->m_x = coor.m_x;
    this->m_y = coor.m_y;
    return *this;
}


