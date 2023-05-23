#include "lre3_bindings.h"


void SetSceneGlobal(LRE3SceneManager* scene)
{
    LRE3GetScriptSystem().PushUserType((void*) scene, "LRE3SceneManager");
    LRE3GetScriptSystem().SetGlobal("scene");
}
/////////////////////////////////////////////////////////////////////////////////

FBIND(LRE3SceneManager, AddObject)
{
    return 0;
}

FBIND(LRE3SceneManager, GetAssets)
{
    GET_SELF(LRE3SceneManager);
    PUSH_UDATA(&(self->assets), LRE3AssetManager);
    return 1;
}

FBIND(LRE3SceneManager, GetCamera)
{
    GET_SELF(LRE3SceneManager);
    PUSH_UDATA(self->GetCamera().get(), LRE3Camera);
    return 1;
}

FBIND(LRE3SceneManager, GetSprite)
{
    GET_SELF(LRE3SceneManager);
    GET_STRING(name, 2);
    PUSH_UDATA(self->GetSprite(name).get(), LRE3SpriteObject);
    return 1;
}

FBIND(LRE3SceneManager, GetRoot)
{
    GET_SELF(LRE3SceneManager);
    PUSH_UDATA(self->GetRoot().get(), LRE3SceneRoot);
    return 1;
}

FBIND(LRE3SceneManager, GetObject)
{
    GET_SELF(LRE3SceneManager);
    GET_STRING(name, 2);
    PUSH_UDATA(self->GetObject(name).get(), LRE3Object);
    return 1;
}

LIB(LRE3SceneManager) = {
    {"get_object", FNAME(LRE3SceneManager, GetObject)},
    {"get_root", FNAME(LRE3SceneManager, GetRoot)},
    {"get_sprite", FNAME(LRE3SceneManager, GetSprite)},
    {"get_camera", FNAME(LRE3SceneManager, GetCamera)},
    {"get_assets", FNAME(LRE3SceneManager, GetAssets)},
    {NULL, NULL}
};

LOPEN(LRE3SceneManager)
