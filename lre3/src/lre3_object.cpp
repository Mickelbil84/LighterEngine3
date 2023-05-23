#include "lre3_object.h"

LRE3Object::LRE3Object(std::string name, glm::vec2 position, float rotation, glm::vec2 scale) :
    m_name(name),
    m_position(position), m_rotation(rotation), m_scale(scale),
    m_pParent(nullptr),
    m_bHiddenInSceneGraph(false),
    m_bHidden(false),
    m_bSelected(false)
{
    UpdateLocalModelMatrix();
    UpdateGlobalModelMatrix();
}

void LRE3Object::Update(double deltaTime)
{
    UpdateLocalModelMatrix();
    UpdateGlobalModelMatrix();
    m_eventSubject.Notify(this, LRE3_EVENT_OBJECT_UPDATE);
}
void LRE3Object::Draw()
{
}
void LRE3Object::Draw(LRE3Shader* shader)
{
}

void LRE3Object::UpdateLocalModelMatrix()
{
    m_localModelMatrix = glm::mat3(1.f);
    m_localModelMatrix = glm::scale(m_localModelMatrix, m_scale);
    m_localModelMatrix = glm::rotate(m_localModelMatrix, m_rotation);
    m_localModelMatrix = glm::translate(m_localModelMatrix, m_position);
}
void LRE3Object::UpdateGlobalModelMatrix()
{
    glm::mat3 parentMatrix = glm::mat3(1.f);
    if (m_pParent) parentMatrix = m_pParent->m_globalModelMatrix;
    m_globalModelMatrix = parentMatrix * m_localModelMatrix;

    // TODO: Get global position and rotation
}

// Create a new copy of the class
std::shared_ptr<LRE3Object> LRE3Object::Duplicate(std::string newName)
{
    std::shared_ptr<LRE3Object> newCopy(new LRE3Object());
    newCopy->SetName(newName);
    newCopy->CopyDataFromOther(this);
    return newCopy;
}
void LRE3Object::CopyDataFromOther(LRE3Object* original)
{
    SetPosition(original->GetPosition());
    SetRotation(original->GetRotation());
    SetScale(original->GetScale());
    SetHiddenInSceneGraph(original->GetHiddenInSceneGraph());
    SetHidden(original->GetHidden());
}
void LRE3Object::Delete()
{
}

glm::mat3 LRE3Object::GetModelMatrix() const
{
    return m_globalModelMatrix;
}

// Moves itself from the current parent to a new one
void LRE3Object::Reparent(LRE3Object* parent)
{
    if (m_pParent)
    {
        m_pParent->RemoveChild(this);
        m_pParent = nullptr;
    }
    if (parent)
    {
        parent->AppendChild(this);
        m_pParent = parent;
    }
}
// Appends new child
void LRE3Object::AppendChild(LRE3Object* child)
{
    m_children.push_back(child);
    child->m_pParent = this;
}
// Removes an existing child
void LRE3Object::RemoveChild(LRE3Object* child)
{
    std::erase(m_children, child);
    child->m_pParent = nullptr;
}
std::vector<LRE3Object*> LRE3Object::GetChildren() const
{
    return m_children;
}
LRE3Object* LRE3Object::GetParent() const
{
    return m_pParent;
}

void LRE3Object::AddRotation(float rot)
{
    m_rotation += rot;
}
void LRE3Object::SetPosition(glm::vec2 position)
{
    m_position = position;
}
void LRE3Object::SetPositionX(float x)
{
    m_position.x = x;
}
void LRE3Object::SetPositionY(float y)
{
    m_position.y = y;
}
void LRE3Object::SetRotation(float rotation)
{
    m_rotation = rotation;
}
void LRE3Object::SetScale(glm::vec2 scale)
{
    m_scale = scale;
}
glm::vec2 LRE3Object::GetPosition() const
{
    return m_position;
}
float LRE3Object::GetRotation() const
{
    return m_rotation;
}
glm::vec2 LRE3Object::GetScale() const
{
    return m_scale;
}
void LRE3Object::SetName(std::string name)
{
    m_name = name;
}
std::string LRE3Object::GetName() const
{
    return m_name;
}
void LRE3Object::SetHiddenInSceneGraph(bool hidden)
{
    m_bHiddenInSceneGraph = hidden;
}
bool LRE3Object::GetHiddenInSceneGraph() const
{
    return m_bHiddenInSceneGraph;
}
void LRE3Object::SetHidden(bool hidden)
{
    m_bHidden = hidden;
}
bool LRE3Object::GetHidden() const
{
    return m_bHidden;
}
void LRE3Object::SetSelected(bool selected)
{
    m_bSelected = selected;
}
bool LRE3Object::GetSelected() const
{
    return m_bSelected;
}

glm::vec2 LRE3Object::GetGlobalPosition() const
{
    return glm::vec2(0.f);
}
float LRE3Object::GetGlobalRotation() const
{
    return 0.f;
}