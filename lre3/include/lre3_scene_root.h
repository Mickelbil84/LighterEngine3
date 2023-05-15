#pragma once

#include "lre3_object.h"

class LRE3SceneRoot : public LRE3Object
{
public:
    LRE3SceneRoot();
    virtual void Update(double deltaTime);
    virtual void Draw();
    virtual void Draw(LRE3Shader* shader);
    void Clear();

private:
    void UpdateRecurse(double deltaTime, LRE3Object* object);
    void DrawRecurse(LRE3Object* object);
    void DrawRecurse(LRE3Object* object, LRE3Shader* shader);
};

CEREAL_REGISTER_TYPE(LRE3SceneRoot);
CEREAL_REGISTER_POLYMORPHIC_RELATION(LRE3Object, LRE3SceneRoot);