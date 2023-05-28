#pragma once

#include "lre3_sprite_object.h"

#include <map>

struct LRE3SpriteAnimation
{
public:
    LRE3SpriteAnimation(int frameStart = 0, int frameCount = 0, int fps = 24): frameStart(frameStart), frameCount(frameCount), fps(fps) {}

    int frameStart, frameCount, fps;
};

class LRE3AnimatedSprite : public LRE3SpriteObject
{
public:
    LRE3AnimatedSprite(std::string name) : LRE3SpriteObject(name) {}

    virtual std::shared_ptr<LRE3Object> Duplicate(std::string newName);
    virtual void Update(double deltaTime);

    void AddAnimation(std::string animationName, int frameStart, int frameCount, int fps)
    {
        m_animations[animationName] = LRE3SpriteAnimation(frameStart, frameCount, fps);
    }
    void SetAnimation(std::string animationName)
    {
        if (m_currAnimation == animationName) return;
        m_currAnimation = animationName;
        m_currFrame = 0;
        m_lastFrameTime = GetRunTime();
        SetTile(0, 0, m_animations[m_currAnimation].frameStart);
    }


protected:
    float m_lastFrameTime;
    std::string m_currAnimation;
    int m_currFrame;
    std::map<std::string, LRE3SpriteAnimation> m_animations;

};