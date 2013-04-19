#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <SFML\Graphics.hpp>
#include <memory>

#include "Drawable.h"
#include "Animation.h"

class Animator
{
    public:
        Animator(bool Play = false, bool Loop = true, float Time = 0.f);
        Animator(std::shared_ptr<Drawable> drawable, Animation* NewAnim, bool Play = false, bool Loop = true, float Time = 0.f);
        virtual ~Animator();

        void SetAnim(Animation* NewAnim);
        Animation* GetAnim();
        void SetFrame(int Frame);
        int GetCurrentFrame();
        void SetFrameTime(float Time);
        float GetFrameTime();
        void SetLoop(bool Loop);
        bool IsLoop();
        void Pause();
        void Play();
        void Stop();
        bool IsPaused();
        bool IsStoped();
        void anim(float ElapsedTime);

    private:
        float myTime;
        float myElapsedTime;
        bool Paused;
        bool myLoop;

        Animation* myAnim;
        std::shared_ptr<Drawable> myDrawable;
        unsigned int myCurrentFrame;

};

#endif // ANIMATOR_H
