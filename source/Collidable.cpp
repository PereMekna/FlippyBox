#include "Coordinates.h"

Coordinates::Coordinates(int x, int y)
{
    if(x <= 800) m_x = x;
    else m_x = 0;

    if (x <= 600) m_y = y;
    else m_y = 0;
}

