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
    m_frames = Cpy.m_frames;
}
//
// Push frame
void Animation::push_frame(const Frame& NewFrame)
{
    m_frames.push_back(NewFrame);
}
//
// Number of frames
size_t Animation::size() const
{
    return m_frames.size();
}

// Get N frame
Frame& Animation::operator [] (size_t N)
{
    return m_frames[N];
}
