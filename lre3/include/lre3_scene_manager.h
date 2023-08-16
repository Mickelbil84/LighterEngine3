#pragma once

#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>

#include <cereal/types/memory.hpp>
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>

#include "lre3_scene_root.h"
#include "lre3_application_settings.h"
#include "lre3_asset_manager.h"
#include "lre3_camera.h"
#include "lre3_sprite_object.h"
#include "lre3_animated_sprite.h"

class LRE3ReorderObserver;

class LRE3SceneManager
{
public:
    LRE3SceneManager();
    
    void Init();
    void Render();
    void Render(int width, int height);
    void Clear();

    void AddCamera(glm::vec2 position = glm::vec2(0.f));
    void AddObject(std::string name, std::string parent="");
    void AddSpriteObject(std::string name, std::string shader, std::string texture, std::string parent="");
    void AddAnimatedSprite(std::string name, std::string shader, std::string texture, std::string parent="");

    std::shared_ptr<LRE3SceneRoot> GetRoot() const;
    std::shared_ptr<LRE3Camera> GetCamera() const;
    std::shared_ptr<LRE3SpriteObject> GetSprite(std::string name);

    void ReorderObjectsByDepth();

    // Object naming
    std::string GetObjectNumberPrefix(std::string objectName);
    int GetObjectNumberSuffix(std::string objectName);
    std::string GetValidObjectName(std::string objectName);

    std::shared_ptr<LRE3Object> GetObject(std::string name);
    void Reparent(std::string object, std::string newParent);
    std::shared_ptr<LRE3Object> DuplicateObject(std::shared_ptr<LRE3Object> obj, std::string parentName, bool topLevel = true);
    void DeleteObject(std::shared_ptr<LRE3Object> obj, bool topLevel = true);

    LRE3ApplicationSettings* applicationSettings;

    LRE3ReorderObserver* reorderObserver;

protected:
    std::shared_ptr<LRE3SceneRoot> root;
    std::shared_ptr<LRE3Camera> camera;

public:
    std::map<std::string, std::shared_ptr<LRE3Object>> objectPool;
    std::map<std::string, std::string> parentLinks;
    std::vector<std::shared_ptr<LRE3Object>> renderPool;

public:
    // Use parent links to fix the scene graph
    void UpdateSceneGraph();
    void UpdateAssets();

    LRE3AssetManager assets;

public:
    template <class Archive>
    void save( Archive & ar ) const
    {
        ar(CEREAL_NVP(assets));
        ar(CEREAL_NVP(objectPool), CEREAL_NVP(parentLinks));
    }

    template <class Archive>
    void load( Archive & ar )
    {
        ar(assets);
        ar(objectPool, parentLinks);
        UpdateSceneGraph();
        UpdateAssets();
    }
};

class LRE3ReorderObserver : public LRE3Observer<LRE3Object>
{
public:
    void SetScene(LRE3SceneManager* scene) {m_pScene = scene;}
    virtual void OnNotify(LRE3Object* sender, LRE3EventType eventType);

protected:
    LRE3SceneManager* m_pScene;
};

void SaveScene(LRE3SceneManager& scene, std::string serializationPath);
void LoadScene(LRE3SceneManager& scene, std::string serializationPath);