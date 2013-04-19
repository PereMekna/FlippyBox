#include "Animator.h"

// Par défault
Animator::Animator(bool play, bool loop, float time)
{
    m_animation = NULL;
    m_currentFrame = 0;
    m_time = time;
    m_elapsedTime = time;
    m_paused = !play;
    m_loop = loop;
}

// Directement avec une Animation
Animator::Animator(std::shared_ptr<Drawable> drawable, Animation* newAnim, bool play, bool loop, float time)
{
    m_time = time;
    m_elapsedTime = time;
    m_paused = !play;
    m_loop = loop;
    m_animation = newAnim;
    m_drawable = drawable;

    set_frame(0);
}

// Destructeur
Animator::~Animator()
{

}

// Comme 'SetImage', sauf qu'on lui fournit l'Animation
void Animator::set_anim(Animation* animation)
{
    m_animation = animation;

    set_frame(0);
}

// Retourne un pointeur sur l'anim
Animation* Animator::get_anim()
{
    return m_animation;
}

// Passer à l'image numéro X
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

//Retourne La frame courante
int Animator::get_currentFrame()
{
    return m_currentFrame;
}

// Fixer le temps entre chaques Frame
void Animator::set_frameTime(float time)
{
    m_time = time;
}

// retourne le temps entre chaques Frame
float Animator::get_frameTime()
{
    return m_time;
}

// Jouer en boucle ?
void Animator::set_loop(bool loop)
{
    m_loop = loop;
}

// Jouer en boucle ?
bool Animator::is_loop()
{
    return m_loop;
}

// Met en pause la lecture
void Animator::pause()
{
    m_paused = true;
}

// Relance la lecture
void Animator::play()
{
    m_paused = false;
}

// Met en pause la lecture, et 'rembobine'
void Animator::stop()
{
    set_frame(0);
    m_elapsedTime = m_time;
    m_paused = true;
}

// Est En pause ?
bool Animator::is_paused()
{
    return m_paused;
}

// Est Stoppé ?
bool Animator::is_stoped()
{
    return (m_paused && (m_currentFrame == 0) && (m_elapsedTime == m_time));
}

// Fonction à appeler à chaque tours de boucle, prend le temps
// écoulé depuis le dernier appel à la fonction en paramètre
void Animator::anim(float elapsedTime)
{
    // Si il n'est pas en pause et que l'animation est valide
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
