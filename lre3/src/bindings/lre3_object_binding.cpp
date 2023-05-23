#include "lre3_bindings.h"


FBIND(LRE3Object, SetPosition)
{
    GET_SELF(LRE3Object);
    GET_NUMBER(x, 2);
    GET_NUMBER(y, 3);
    self->SetPosition(glm::vec2(x,y));
    return 0;
}
FBIND(LRE3Object, SetRotation)
{
    GET_SELF(LRE3Object);
    GET_NUMBER(rotation, 2);
    self->SetRotation((float)rotation);
    return 0;
}
FBIND(LRE3Object, SetScale)
{
    GET_SELF(LRE3Object);
    GET_NUMBER(x, 2);
    GET_NUMBER(y, 3);
    self->SetScale(glm::vec2(x,y));
    return 0;
}
FBIND(LRE3Object, GetPosition)
{
    GET_SELF(LRE3Object);
    glm::vec2 pos = self->GetPosition();
    PUSH_NUMBER(pos.x);
    PUSH_NUMBER(pos.y);
    return 2;
}
FBIND(LRE3Object, GetRotation)
{
    GET_SELF(LRE3Object);
    PUSH_NUMBER(self->GetRotation());
    return 1;
}
FBIND(LRE3Object, GetScale)
{
    GET_SELF(LRE3Object);
    glm::vec2 scale = self->GetScale();
    PUSH_NUMBER(scale.x);
    PUSH_NUMBER(scale.y);
    return 2;
}
FBIND(LRE3Object, SetName)
{
    GET_SELF(LRE3Object);
    GET_STRING(name, 2);
    self->SetName(name);
    return 0;
}
FBIND(LRE3Object, GetName)
{
    GET_SELF(LRE3Object);
    PUSH_STRING(self->GetName());
    return 1;
}
FBIND(LRE3Object, SetHiddenInSceneGraph)
{
    GET_SELF(LRE3Object);
    GET_BOOL(hidden, 2);
    self->SetHiddenInSceneGraph(hidden);
    return 0;
}
FBIND(LRE3Object, GetHiddenInSceneGraph)
{
    GET_SELF(LRE3Object);
    PUSH_BOOL(self->GetHiddenInSceneGraph());
    return 1;
}
FBIND(LRE3Object, SetHidden)
{
    GET_SELF(LRE3Object);
    GET_BOOL(hidden, 2);
    self->SetHidden(hidden);
    return 0;
}
FBIND(LRE3Object, GetHidden)
{
    GET_SELF(LRE3Object);
    PUSH_BOOL(self->GetHidden());
    return 1;
}
FBIND(LRE3Object, SetSelected)
{
    GET_SELF(LRE3Object);
    GET_BOOL(selected, 2);
    self->SetSelected(selected);
    return 0;
}
FBIND(LRE3Object, GetSelected)
{
    GET_SELF(LRE3Object);
    PUSH_BOOL(self->GetSelected());
    return 1;
}

LIB(LRE3Object) = {
    {"set_position", FNAME(LRE3Object,SetPosition)},
    {"set_rotation", FNAME(LRE3Object,SetRotation)},
    {"set_scale", FNAME(LRE3Object,SetScale)},
    {"get_position", FNAME(LRE3Object,GetPosition)},
    {"get_rotation", FNAME(LRE3Object,GetRotation)},
    {"get_scale", FNAME(LRE3Object,GetScale)},
    {"set_name", FNAME(LRE3Object,SetName)},
    {"get_name", FNAME(LRE3Object,GetName)},
    {"set_hidden_in_scene_graph", FNAME(LRE3Object,SetHiddenInSceneGraph)},
    {"get_hidden_in_scene_graph", FNAME(LRE3Object,GetHiddenInSceneGraph)},
    {"set_hidden", FNAME(LRE3Object,SetHidden)},
    {"get_hidden", FNAME(LRE3Object,GetHidden)},
    {"set_selected", FNAME(LRE3Object,SetSelected)},
    {"get_selected", FNAME(LRE3Object,GetSelected)},
    {NULL, NULL}
};
LOPEN(LRE3Object)