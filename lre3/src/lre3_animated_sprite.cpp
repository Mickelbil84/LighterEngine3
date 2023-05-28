#include "lre3_animated_sprite.h"

std::shared_ptr<LRE3Object> LRE3AnimatedSprite::Duplicate(std::string newName)
{
    return nullptr;
}
void LRE3AnimatedSprite::Update(double deltaTime)
{
    LRE3SpriteObject::Update(deltaTime);

    if (m_currAnimation.size() > 0)
    {
        LRE3SpriteAnimation animation = m_animations[m_currAnimation];
        float nextFrameTime = m_lastFrameTime + (1.f / (float)animation.fps);
        if (GetRunTime() > nextFrameTime)
        {
            m_currFrame = (m_currFrame + 1) % animation.frameCount;
            SetTile(0, 0, animation.frameStart + m_currFrame);
            m_lastFrameTime = GetRunTime();
        }
    }
}