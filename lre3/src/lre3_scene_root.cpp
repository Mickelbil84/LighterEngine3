#include "lre3_scene_root.h"

LRE3SceneRoot::LRE3SceneRoot() : LRE3Object("Root")
{

}

void LRE3SceneRoot::UpdateRecurse(double deltaTime, LRE3Object* object)
{
    for (auto child : object->GetChildren())   
    {
        if (!child)
            continue;
        child->Update(deltaTime);
        UpdateRecurse(deltaTime, child);
    }
}

void LRE3SceneRoot::DrawRecurse(LRE3Object* object)
{
    if (object->GetHidden())
        return;

    for (auto child : object->GetChildren())   
    {
        if (!child)
            continue;
        child->Draw();
        DrawRecurse(child);
    }
}
void LRE3SceneRoot::DrawRecurse(LRE3Object* object, LRE3Shader* shader)
{
    if (object->GetHidden())
        return;

    for (auto child : object->GetChildren())   
    {
        if (!child)
            continue;
        child->Draw(shader);
        DrawRecurse(child, shader);
    }
}

void LRE3SceneRoot::Update(double deltaTime)
{
    UpdateRecurse(deltaTime, this);
}
void LRE3SceneRoot::Draw()
{
    DrawRecurse(this);
}
void LRE3SceneRoot::Draw(LRE3Shader* shader)
{
    DrawRecurse(this, shader);
}