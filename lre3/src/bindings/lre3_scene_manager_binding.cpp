#include "lre3_bindings.h"


void SetSceneGlobal(LRE3SceneManager* scene)
{
    LRE3GetScriptSystem().PushUserType((void*) scene, "LRE3SceneManager");
    LRE3GetScriptSystem().SetGlobal("scene");
}
/////////////////////////////////////////////////////////////////////////////////

FBIND(LRE3SceneManager, AddObject)
{
    GET_SELF(LRE3SceneManager);
    GET_STRING(name, 2);
    GET_STRING_OR_NIL(parent, 3);
    self->AddObject(name, parent);
    PUSH_UDATA(self->GetObject(name).get(), LRE3Object);
    return 1;
}
FBIND(LRE3SceneManager, AddSprite)
{
    GET_SELF(LRE3SceneManager);
    GET_STRING(name, 2);
    GET_STRING(shader, 3);
    GET_STRING(texture, 4);
    GET_STRING_OR_NIL(parent, 5);
    self->AddSpriteObject(name, shader, texture, parent);
    PUSH_UDATA(self->GetObject(name).get(), LRE3SpriteObject);
    return 1;
}

FBIND(LRE3SceneManager, DeleteObject)
{
    GET_SELF(LRE3SceneManager);
    GET_UDATA(obj, LRE3Object, 2);
    RELEASE_UDATA(obj);
    self->DeleteObject(self->GetObject(obj->GetName()));
    return 0;
}
FBIND(LRE3SceneManager, DuplicateObject)
{
    GET_SELF(LRE3SceneManager);
    GET_UDATA_WITHTYPE(obj, LRE3Object, 2);
    GET_STRING(parent, 3);
    PUSH_UDATA_STR(self->DuplicateObject(self->GetObject(obj->GetName()), parent).get(), actual_tname);
    return 1;
}
FBIND(LRE3SceneManager, Reparent)
{
    GET_SELF(LRE3SceneManager);
    GET_UDATA(obj, LRE3Object, 2);
    GET_UDATA(parent, LRE3Object, 3);
    self->Reparent(obj->GetName(), parent->GetName());
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
    {"add_object", FNAME(LRE3SceneManager, AddObject)},
    {"add_sprite", FNAME(LRE3SceneManager, AddSprite)},

    {"delete_object", FNAME(LRE3SceneManager, DeleteObject)},
    {"duplicate_object", FNAME(LRE3SceneManager, DuplicateObject)},
    {"reparent", FNAME(LRE3SceneManager, Reparent)},

    {"get_object", FNAME(LRE3SceneManager, GetObject)},
    {"get_root", FNAME(LRE3SceneManager, GetRoot)},
    {"get_sprite", FNAME(LRE3SceneManager, GetSprite)},
    {"get_camera", FNAME(LRE3SceneManager, GetCamera)},

    {"get_assets", FNAME(LRE3SceneManager, GetAssets)},
    {NULL, NULL}
};

LOPEN(LRE3SceneManager)
