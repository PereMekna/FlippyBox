#include "Animation.h"

//
// Constructor
Animation::Animation()
{}
//
// Destructor
Animation::~Animation()
{}
//
// Copy
Animation::Animation(const Animation& Cpy)
{
    myFrame = Cpy.myFrame;
}
//
// Push frame
void Animation::PushFrame(const Frame& NewFrame)
{
    myFrame.push_back(NewFrame);
}
//
// Number of frames
size_t Animation::Size() const
{
    return myFrame.size();
}

// Acc�s a la frame num�ro N
Frame& Animation::operator [] (size_t N)
{
    return myFrame[N];
}
