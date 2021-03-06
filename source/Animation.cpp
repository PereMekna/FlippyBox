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
//
// Get N frame
Frame& Animation::operator [] (size_t N)
{
    return m_frames[N];
}
//
// Load a animation from a file (with link)
bool Animation::load_from_file(std::string link)
{
    std::ifstream AnimFile(link, std::ios::in);
    if(!AnimFile) return false;

    std::string linkImage;
    int nbFrames;
    int widthFrame;
    int heightFrame;
    AnimFile >> linkImage >> nbFrames >> widthFrame >> heightFrame;

    sf::Image Img;
    Img.loadFromFile(linkImage);
    Img.createMaskFromColor(sf::Color::Black);
    sf::Texture Txtr;
    Txtr.loadFromImage(Img);

    int x,y;
    for(int i = 0; i < nbFrames; ++i)
    {
        AnimFile >> x >> y;
        this->push_frame(Frame(std::make_shared<sf::Texture>(Txtr), sf::Rect<int>(x, y, widthFrame, heightFrame)));
    }

    return true;
}
