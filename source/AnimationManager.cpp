#include "AnimationManager.h"

AnimationManager AnimationManager::m_instance = AnimationManager();

AnimationManager::AnimationManager()
{
    //ctor
}

AnimationManager::~AnimationManager()
{
    //dtor
}

AnimationManager& AnimationManager::Instance()
{
    return m_instance;
}

std::shared_ptr<Animation> AnimationManager::get_animation(std::string animName)
{
   std::map<std::string, std::shared_ptr<Animation> >::const_iterator it = m_animations.find(animName);
   if(it != m_animations.end())
        return it->second;
   else
        return create_animation(animName);
}

std::shared_ptr<Animation> AnimationManager::create_animation(std::string animName)
{
    std::shared_ptr<Animation> anim(std::make_shared<Animation>());
    if(anim->load_from_file(animName + ".anim"))
    {
        m_animations.insert(std::make_pair(animName, anim));
        return anim;
    }

    return NULL;
}
