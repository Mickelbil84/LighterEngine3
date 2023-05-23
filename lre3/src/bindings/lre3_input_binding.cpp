#include "lre3_bindings.h"


FBIND(LRE3Input, GetKeystate)
{
    GET_SELF(LRE3Input);
    GET_NUMBER(scancode, 2);
    PUSH_BOOL((bool)self->keyboard[(int)scancode]);
    return 1;
}

FBIND(LRE3Input, GetMouseRel)
{
    GET_SELF(LRE3Input);
    PUSH_NUMBER((double)self->xrel);
    PUSH_NUMBER((double)self->yrel);
    return 2;
}

FBIND(LRE3Input, GetLMouseDown)
{
    GET_SELF(LRE3Input);
    PUSH_BOOL(self->bLeftMouseDown);
    return 1;
}

FBIND(LRE3Input, GetRMouseDown)
{
    GET_SELF(LRE3Input);
    PUSH_BOOL(self->bRightMouseDown);
    return 1;
}

LIB(LRE3Input) = {
    {"get_keystate", FNAME(LRE3Input, GetKeystate)},
    {"get_mouse_rel", FNAME(LRE3Input, GetMouseRel)},
    {"get_lmouse_down", FNAME(LRE3Input, GetLMouseDown)},
    {"get_rmouse_down", FNAME(LRE3Input, GetRMouseDown)},
    {NULL, NULL}
};
LOPEN(LRE3Input)