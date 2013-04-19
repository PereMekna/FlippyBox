#ifndef ANIMATION_H
#define ANIMATION_H

#include "Frame.h"

class Animation
{
    public:
        Animation();
        Animation(const Animation& Cpy);
        virtual ~Animation();

        void PushFrame(const Frame& NewFrame);
        size_t Size() const;
        Frame& operator [] (size_t N);

    private:
        std::vector<Frame> myFrame;
};

#endif // ANIMATION_H
