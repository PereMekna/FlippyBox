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
        Animator(std::shared_ptr<Drawable> drawable, std::shared_ptr<Animation> anim, bool play = false, bool loop = true, float time = 0.f);
        virtual ~Animator();

        void set_anim(std::shared_ptr<Animation> anim);
        std::shared_ptr<Animation> get_anim();
        void set_frame(int frame);
        int get_currentFrame();
        void set_frameTime(float time);
        float get_frameTime();
        void set_loop(bool loop);
        bool is_loop();
        void pause();
        void play();
        void stop();
        bool is_paused();
        bool is_stopped();
        void anim(float elapsedTime);

    private:
        float m_time;
        float m_elapsedTime;
        bool m_paused;
        bool m_loop;

        std::shared_ptr<Animation> m_animation;
        std::shared_ptr<Drawable> m_drawable;
        unsigned int m_currentFrame;

};

#endif // ANIMATOR_H
