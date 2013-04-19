#include "Animator.h"

// Par défault
Animator::Animator(bool Play, bool Loop, float Time)
{
    myAnim = NULL;
    myCurrentFrame = 0;
    myTime = Time;
    myElapsedTime = Time;
    Paused = !Play;
    myLoop = Loop;
}

// Directement avec une Animation
Animator::Animator(std::shared_ptr<Drawable> drawable, Animation* NewAnim, bool Play, bool Loop, float Time)
{
    myTime = Time;
    myElapsedTime = Time;
    Paused = !Play;
    myLoop = Loop;
    myAnim = NewAnim;
    myDrawable = drawable;

    SetFrame(0);
}

// Destructeur
Animator::~Animator()
{

}

// Comme 'SetImage', sauf qu'on lui fournit l'Animation
void Animator::SetAnim(Animation* NewAnim)
{
    myAnim = NewAnim;

    SetFrame(0);
}

// Retourne un pointeur sur l'anim
Animation* Animator::GetAnim()
{
    return myAnim;
}

// Passer à l'image numéro X
void Animator::SetFrame(int Frame)
{
    if ( myAnim != NULL)
    {
        if (myAnim->Size() > 0)
        {
            if ((*myAnim)[Frame].Texture != NULL)
                {
                    sf::Sprite sprite;
                    sprite.setTexture(*((*myAnim)[Frame].Texture));
                    sprite.setTextureRect((*myAnim)[Frame].Rect);
                    sprite.setColor((*myAnim)[Frame].Color);

                    myDrawable->set_sprite(sprite);

                    myCurrentFrame = Frame;
                }
        }
    }
}

//Retourne La frame courante
int Animator::GetCurrentFrame()
{
    return myCurrentFrame;
}

// Fixer le temps entre chaques Frame
void Animator::SetFrameTime(float Time)
{
    myTime = Time;
}

// retourne le temps entre chaques Frame
float Animator::GetFrameTime()
{
    return myTime;
}

// Jouer en boucle ?
void Animator::SetLoop(bool Loop)
{
    myLoop = Loop;
}

// Jouer en boucle ?
bool Animator::IsLoop()
{
    return myLoop;
}

// Met en pause la lecture
void Animator::Pause()
{
    Paused = true;
}

// Relance la lecture
void Animator::Play()
{
    Paused = false;
}

// Met en pause la lecture, et 'rembobine'
void Animator::Stop()
{
    SetFrame(0);
    myElapsedTime = myTime;
    Paused = true;
}

// Est En pause ?
bool Animator::IsPaused()
{
    return Paused;
}

// Est Stoppé ?
bool Animator::IsStoped()
{
    return (Paused && (myCurrentFrame == 0) && (myElapsedTime == myTime));
}

// Fonction à appeler à chaque tours de boucle, prend le temps
// écoulé depuis le dernier appel à la fonction en paramètre
void Animator::anim(float ElapsedTime)
{
    // Si il n'est pas en pause et que l'animation est valide
    if (!Paused && myAnim != NULL)
    {
        // on retranche le temps écoulé a notre compteur
        myElapsedTime -= ElapsedTime;

        // Si Le temps entre chaque frame est atteint
        if (myElapsedTime <= 0.f)
        {
            // On réinitialise notre compteur
            myElapsedTime = myTime;

            // On passe a la frame suivante
            if (myCurrentFrame + 1 < myAnim->Size())
                myCurrentFrame++;
            else
            {
                // Ou on a la premiere
                if (myLoop)
                    myCurrentFrame = 0;
                else
                {
                    // Si le mode Loop est désactivé, on stop l'animation
                    Stop();
                }
            }

            // On change la frame
            SetFrame(myCurrentFrame);
        }
    }
}
