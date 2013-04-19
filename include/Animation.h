#ifndef ANIMATION_H
#define ANIMATION_H

#include "Frame.h"

class Animation
{
    public:
        Animation();
        Animation(const Animation& Cpy);
        virtual ~Animation();

        void push_frame(const Frame& NewFrame);
        size_t size() const;
        Frame& operator [] (size_t N);

    private:
        std::vector<Frame> m_frames;
};

#endif // ANIMATION_H
