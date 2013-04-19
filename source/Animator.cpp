#include "Animator.h"
//
// Constructor
Animator::Animator(bool play, bool loop, float time)
{
    m_animation = NULL;
    m_currentFrame = 0;
    m_time = time;
    m_elapsedTime = time;
    m_paused = !play;
    m_loop = loop;
}
//
// Constructor with Animation
Animator::Animator(std::shared_ptr<Drawable> drawable, std::shared_ptr<Animation> anim, bool play, bool loop, float time)
{
    m_time = time;
    m_elapsedTime = time;
    m_paused = !play;
    m_loop = loop;
    m_animation = anim;
    m_drawable = drawable;

    set_frame(0);
}
//
// Destructor
Animator::~Animator()
{

}
//
// Set a new animation
void Animator::set_anim(std::shared_ptr<Animation> animation)
{
    m_animation = animation;

    set_frame(0);
}
//
// Get animation
std::shared_ptr<Animation> Animator::get_anim()
{
    return m_animation;
}
//
// Set frame to animate
void Animator::set_frame(int frame)
{
    if ( m_animation != NULL)
    {
        if (m_animation->size() > 0)
        {
            if ((*m_animation)[frame].texture != NULL)
                {
                    sf::Sprite sprite;
                    sprite.setTexture(*((*m_animation)[frame].texture));
                    sprite.setTextureRect((*m_animation)[frame].rect);
                    sprite.setColor((*m_animation)[frame].color);

                    m_drawable->set_sprite(sprite);

                    m_currentFrame = frame;
                }
        }
    }
}
//
// Get current frame
int Animator::get_currentFrame()
{
    return m_currentFrame;
}
//
// Set time between frame
void Animator::set_frameTime(float time)
{
    m_time = time;
}
//
// Get time between frame
float Animator::get_frameTime()
{
    return m_time;
}
//
// Set loop
void Animator::set_loop(bool loop)
{
    m_loop = loop;
}
//
// Get loop
bool Animator::is_loop()
{
    return m_loop;
}
//
// Met en pause la lecture
void Animator::pause()
{
    m_paused = true;
}
//
// Play
void Animator::play()
{
    m_paused = false;
}
//
// Stop and rewind
void Animator::stop()
{
    set_frame(0);
    m_elapsedTime = m_time;
    m_paused = true;
}
//
// Get paused
bool Animator::is_paused()
{
    return m_paused;
}
//
// Get stopped
bool Animator::is_stopped()
{
    return (m_paused && (m_currentFrame == 0) && (m_elapsedTime == m_time));
}
//
// Update animation with elapsed time
void Animator::anim(float elapsedTime)
{
    if (!m_paused && m_animation != NULL)
    {
        // on retranche le temps écoulé a notre compteur
        m_elapsedTime -= elapsedTime;
        // Si Le temps entre chaque frame est atteint
        if (m_elapsedTime <= 0.f)
        {
            // On réinitialise notre compteur
            m_elapsedTime = m_time;

            // On passe a la frame suivante
            if (m_currentFrame + 1 < m_animation->size())
                m_currentFrame++;
            else
            {
                // Ou on a la premiere
                if (m_loop)
                    m_currentFrame = 0;
                else
                {
                    // Si le mode Loop est désactivé, on stop l'animation
                    stop();
                }
            }
            // On change la frame
            set_frame(m_currentFrame);
        }
    }
}
