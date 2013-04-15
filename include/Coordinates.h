/*

    Coordinates.h
    Provide abstraction for coordinates


*/
#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
    public:
        explicit Coordinates(int x, int y);
        Coordinates(const Coordinates& coor);
        Coordinates& operator =(const Coordinates& coor);


    private:
        int m_x;
        int m_y;
};



#endif
