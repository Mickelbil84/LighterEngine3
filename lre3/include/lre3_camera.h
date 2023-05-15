#pragma once

#include "lre3_object.h"

#include <gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>

class LRE3Camera : public LRE3Object
{
public:
    LRE3Camera();

    glm::mat3 GetViewMatrix() const;
    glm::mat3 GetProjectionMatrix(float aspectRatio=-1.f) const;

    float GetAspectRatio() const;
    void SetAspectRatio(float aspectRatio);
    float GetZoom() const;
    void SetZoom(float zoom);

protected:
    float m_aspectRatio, m_zoom;
};