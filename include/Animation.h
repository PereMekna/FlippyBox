/*

    Animation.h
    Provide ressource class for animation.
    Basically a animation is a vector of frames.

*/
#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <fstream>

#include "Frame.h"

class Animation
{
    public:
        Animation();
        Animation(const Animation& Cpy);
        ~Animation();

        void push_frame(const Frame& NewFrame);
        size_t size() const;
        Frame& operator [] (size_t N);

        bool load_from_file(std::string link);

    private:
        std::vector<Frame> m_frames;
};

#endif // ANIMATION_H
