#include "lre3_bindings.h"

FBIND(LRE3AnimatedSprite, AddAnimation)
{
    GET_SELF(LRE3AnimatedSprite);
    GET_STRING(animationName, 2);
    GET_NUMBER(frameStart, 3);
    GET_NUMBER(frameCount, 4);
    GET_NUMBER(fps, 5);
    self->AddAnimation(animationName, frameStart, frameCount, fps);
    return 0;
}

FBIND(LRE3AnimatedSprite, SetAnimation)
{
    GET_SELF(LRE3AnimatedSprite);
    GET_STRING(animationName, 2);
    self->SetAnimation(animationName);
    return 0;
}

LIB(LRE3AnimatedSprite) = {
    {"add_animation", FNAME(LRE3AnimatedSprite, AddAnimation)},
    {"set_animation", FNAME(LRE3AnimatedSprite, SetAnimation)},
    {NULL, NULL}
};
LOPEN(LRE3AnimatedSprite)