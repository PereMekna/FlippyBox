/*

    Collidable.h
    Provide collidable objects.
    Abstract.

*/
#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <Box2D\Box2D.h>

class Collidable
{
    public:
        ~Collidable(){}
    protected:
        Collidable();
    private:
        b2FixtureDef m_fixtureDef;
        b2BodyDef m_bodyDef;
        b2PolygonShape m_polygonShape;

        b2Body* m_body;

        Collidable(const Collidable&);              // Non copiable
        Collidable& operator=(const Collidable&);   // Non copiable
};

#endif

