/*

    ImageManager.h
    Creates, loads and returns Image.
    Manage Image, avoiding duplications.

*/
#ifndef ImageMANAGER_H
#define ImageMANAGER_H

#include <memory>
#include <map>
#include <string>

#include <SFML\Graphics.hpp>

class ImageManager
{
    public:
        static ImageManager& Instance();

        std::shared_ptr<sf::Image> get_image(std::string link);
        void delete_image(std::string link);

    private:
        static ImageManager m_instance;
        ImageManager();
        ~ImageManager();
        ImageManager& operator= (const ImageManager&);
        ImageManager (const ImageManager&);

        std::shared_ptr<sf::Image> create_image(std::string link);
        std::map<std::string, std::shared_ptr<sf::Image> > m_images;
};

#endif // ImageMANAGER_H
