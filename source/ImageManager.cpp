#include "ImageManager.h"
//
// Singleton
ImageManager ImageManager::m_instance = ImageManager();
//
//
ImageManager::ImageManager()
{}
//
//
ImageManager::~ImageManager()
{}
//
// Singleton
ImageManager& ImageManager::Instance()
{
    return m_instance;
}
//
// Return a loaded image and if not the manager tries to load one
std::shared_ptr<sf::Image> ImageManager::get_image(std::string link)
{
   std::map<std::string, std::shared_ptr<sf::Image> >::const_iterator it = m_images.find(link);
   if(it != m_images.end())
        return it->second;
   else
        return create_image(link);
}
//
// Load an image
std::shared_ptr<sf::Image> ImageManager::create_image(std::string link)
{
    std::shared_ptr<sf::Image> image(std::make_shared<sf::Image>());
    if(image->loadFromFile(link))
    {
        m_images.insert(std::make_pair(link, image));
        return image;
    }
    return NULL;
}
//
// Delete an image
void ImageManager::delete_image(std::string link)
{
    std::map<std::string, std::shared_ptr<sf::Image> >::iterator it = m_images.find(link);
    if(it != m_images.end())
    {
        m_images.erase(it);
    }
}
