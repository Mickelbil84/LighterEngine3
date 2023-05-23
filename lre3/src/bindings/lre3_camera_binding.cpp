#include "lre3_bindings.h"


FBIND(LRE3Camera, GetZoom)
{
    GET_SELF(LRE3Camera);
    double zoom = self->GetZoom();
    PUSH_NUMBER(zoom);
    return 1;
}

FBIND(LRE3Camera, SetZoom)
{
    GET_SELF(LRE3Camera);
    GET_NUMBER(zoom, 2);
    self->SetZoom(zoom);
    return 0;
}

LIB(LRE3Camera) = {
    {"get_zoom", FNAME(LRE3Camera, GetZoom)},
    {"set_zoom", FNAME(LRE3Camera, SetZoom)},
    {NULL, NULL}
};
LOPEN(LRE3Camera)