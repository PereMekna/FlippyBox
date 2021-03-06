/*

    AnimationManager.h
    Creates, loads and returns animation.
    Manage animation, avoiding duplications.

*/
#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <memory>
#include <map>
#include <string>

#include "Animation.h"

class AnimationManager
{
    public:
        static AnimationManager& Instance();

        std::shared_ptr<Animation> get_animation(std::string link);
        void delete_animation(std::string link);

    private:
        static AnimationManager m_instance;
        AnimationManager();
        ~AnimationManager();
        AnimationManager& operator= (const AnimationManager&);
        AnimationManager (const AnimationManager&);

        std::shared_ptr<Animation> create_animation(std::string link);
        std::map<std::string, std::shared_ptr<Animation> > m_animations;
};

#endif // ANIMATIONMANAGER_H
