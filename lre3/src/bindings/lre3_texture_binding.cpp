#include "lre3_bindings.h"


FBIND(LRE3Texture, GetAtlasSize)
{
    GET_SELF(LRE3Texture);
    PUSH_NUMBER(self->GetAtlasRows());
    PUSH_NUMBER(self->GetAtlasCols());
    return 2;
}

LIB(LRE3Texture) = {
    {"get_atlas_size", FNAME(LRE3Texture, GetAtlasSize)},
    {NULL, NULL}
};

LOPEN(LRE3Texture)