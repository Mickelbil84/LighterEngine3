#include "lre3_camera.h"

LRE3Camera::LRE3Camera() : m_zoom(1.f), m_aspectRatio(1.f)
{
}

glm::mat3 LRE3Camera::GetViewMatrix() const
{
    return glm::inverse(GetModelMatrix());
}
glm::mat3 LRE3Camera::GetProjectionMatrix(float aspectRatio) const
{
    if (aspectRatio < 0)
        aspectRatio = m_aspectRatio;
    return glm::scale(glm::mat3(1.f), m_zoom * glm::vec2(1.f, aspectRatio));
}

float LRE3Camera::GetAspectRatio() const
{
    return m_aspectRatio;
}
void LRE3Camera::SetAspectRatio(float aspectRatio)
{
    m_aspectRatio = aspectRatio;
}
float LRE3Camera::GetZoom() const
{
    return m_zoom;
}
void LRE3Camera::SetZoom(float zoom)
{
    m_zoom = zoom;
}