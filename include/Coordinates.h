/*

    Coordinates.h
    Provide abstraction for coordinates.


*/
#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
    public:
        explicit Coordinates(int x, int y);
        Coordinates(const Coordinates& coor);

        Coordinates& operator=(const Coordinates& coor);

        int x;
        int y;
};
        bool operator==(const Coordinates& c1, const Coordinates& c2);

#endif
