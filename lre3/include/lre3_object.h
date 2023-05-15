#pragma once

#include <string>
#include <vector>
#include <memory>

#include <cereal/cereal.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/archives/json.hpp>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>

#include "lre3_shader.h"
#include "lre3_utils.h"

// The most basic entity in the framework. Each element in the scene is an object.
// An object has a local transform (which is in relation to its parent).
// Since each object has pointers to its parent and children, they implicitly
// form a scene graph.
class LRE3Object
{
public:
    LRE3Object(std::string name = "", glm::vec2 position = glm::vec2(0.f), float rotation = 0.f, glm::vec2 scale = glm::vec2(1.f));

    virtual void Update(double deltaTime);
    virtual void Draw();
    virtual void Draw(LRE3Shader* shader);

    // Create a new copy of the class
    virtual std::shared_ptr<LRE3Object> Duplicate(std::string newName);
    void CopyDataFromOther(LRE3Object* original);
    virtual void Delete();

    glm::mat3 GetModelMatrix() const;

    // Moves itself from the current parent to a new one
    void Reparent(LRE3Object* parent);
    // Appends new child
    void AppendChild(LRE3Object* child);
    // Removes an existing child
    void RemoveChild(LRE3Object* child);
    std::vector<LRE3Object*> GetChildren() const;
    LRE3Object* GetParent() const;

    void AddRotation(float rot);
    void SetPosition(glm::vec2 position);
    void SetPositionX(float x);
    void SetPositionY(float y);
    void SetRotation(float rotation);
    void SetScale(glm::vec2 scale);
    glm::vec2 GetPosition() const;
    float GetRotation() const;
    glm::vec2 GetScale() const;
    void SetName(std::string name);
    std::string GetName() const;
    void SetHiddenInSceneGraph(bool hidden);
    bool GetHiddenInSceneGraph() const;
    void SetHidden(bool hidden);
    bool GetHidden() const;
    void SetSelected(bool selected);
    bool GetSelected() const;

    glm::vec2 GetGlobalPosition() const;
    float GetGlobalRotation() const;

    template <class Archive>
    void serialize( Archive & ar )
    {
        ar(CEREAL_NVP(m_position), CEREAL_NVP(m_rotation), CEREAL_NVP(m_scale));
        ar(CEREAL_NVP(m_globalPosition), CEREAL_NVP(m_globalRotation));
        ar(CEREAL_NVP(m_localModelMatrix), CEREAL_NVP(m_globalModelMatrix));
        ar(CEREAL_NVP(m_name), CEREAL_NVP(m_bHiddenInSceneGraph), CEREAL_NVP(m_bHidden));
    }

protected:
    
    /////////////////////
    // Transform vectors
    /////////////////////
    
    glm::vec2 m_position;
    float m_rotation;
    glm::vec2 m_scale;

    glm::vec2 m_globalPosition;
    float m_globalRotation;

    //////////////////
    // Model Matrices
    //////////////////

    glm::mat3 m_localModelMatrix, m_globalModelMatrix;

    ///////////////
    // Scene Graph
    ///////////////

    LRE3Object* m_pParent;
    std::vector<LRE3Object*> m_children;
    std::string m_name;
    bool m_bHiddenInSceneGraph;
    bool m_bHidden;
    bool m_bSelected; // Used to draw debug outline

protected:
    // Updates the local model matrix of the object (based on the transform vectors)
    virtual void UpdateLocalModelMatrix();
    // Updates the global model matrix, with respect to the parent object
    virtual void UpdateGlobalModelMatrix();
};

CEREAL_REGISTER_TYPE(LRE3Object);