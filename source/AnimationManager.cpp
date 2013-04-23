#include "AnimationManager.h"
//
// Singleton
AnimationManager AnimationManager::m_instance = AnimationManager();
//
// Constructor
AnimationManager::AnimationManager()
{}
//
// Destructor
AnimationManager::~AnimationManager()
{}
//
// Singleton
AnimationManager& AnimationManager::Instance()
{
    return m_instance;
}
//
// Return a loaded animation and if not the manager tries to load one
std::shared_ptr<Animation> AnimationManager::get_animation(std::string animName)
{
   std::map<std::string, std::shared_ptr<Animation> >::const_iterator it = m_animations.find(animName);
   if(it != m_animations.end())
        return it->second;
   else
        return create_animation(animName);
}
//
// Load a animation
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
//
// Delete an animation
void AnimationManager::delete_animation(std::string animName)
{
    std::map<std::string, std::shared_ptr<Animation> >::iterator it = m_animations.find(animName);
    if(it != m_animations.end())
    {
        m_animations.erase(it);
    }
}
