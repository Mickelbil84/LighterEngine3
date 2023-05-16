#include "lre3_scene_manager.h"

void SaveScene(LRE3SceneManager& scene, std::string serializationPath)
{
    std::ofstream fp(serializationPath, std::ofstream::out);
    {
        cereal::JSONOutputArchive oarchive(fp);
        oarchive(CEREAL_NVP(scene));
    }
}
void LoadScene(LRE3SceneManager& scene, std::string serializationPath)
{
    std::ifstream fp(serializationPath, std::ofstream::in);
    {
        cereal::JSONInputArchive iarchive(fp);
        iarchive(scene);
    }
}

void LRE3SceneManager::Init()
{
    root = std::shared_ptr<LRE3SceneRoot>(new LRE3SceneRoot());
}
void LRE3SceneManager::Render()
{
    for (const auto& [key, value] : assets.m_shaders)
    {
        LRE3Shader* shader = assets.GetShader(key);
        shader->Use();
        shader->Uniform("view", GetCamera()->GetViewMatrix());
        shader->Uniform("projection", GetCamera()->GetProjectionMatrix());
    }
    glViewport(0, 0, applicationSettings->windowWidth, applicationSettings->windowHeight);
    GetRoot()->Draw();
}
void LRE3SceneManager::Clear()
{
    assets.Clear();
    objectPool.clear();
    parentLinks.clear();
    this->Init();
}

void LRE3SceneManager::AddCamera(glm::vec2 position)
{
    camera = std::shared_ptr<LRE3Camera>(new LRE3Camera());
    camera->SetPosition(position);
    camera->SetHiddenInSceneGraph(true);
    objectPool["camera"] = std::static_pointer_cast<LRE3Object>(camera);
    parentLinks["camera"] = "";
    UpdateSceneGraph();
}
void LRE3SceneManager::AddObject(std::string name, std::string parent)
{
    std::shared_ptr<LRE3Object> obj(new LRE3Object(name));
    objectPool[name] = obj;
    parentLinks[name] = parent;
    UpdateSceneGraph();
}
void LRE3SceneManager::AddSpriteObject(std::string name, std::string shader, std::string texture, std::string parent)
{
    std::shared_ptr<LRE3SpriteObject> obj(new LRE3SpriteObject(name));
    if (texture.size() > 0)
        obj->SetTexture(assets.GetTexture(texture));
    else
        obj->SetTexture(nullptr);
    obj->SetShader(assets.GetShader(shader));
    objectPool[name] = std::static_pointer_cast<LRE3Object>(obj);
    parentLinks[name] = parent;
    UpdateSceneGraph();
}

std::shared_ptr<LRE3SceneRoot> LRE3SceneManager::GetRoot() const
{
    return root;
}

std::shared_ptr<LRE3Camera> LRE3SceneManager::GetCamera() const
{
     return camera;
}

std::string LRE3SceneManager::GetObjectNumberPrefix(std::string objectName)
{
    size_t idx = objectName.find_last_not_of("1234567890");
    return objectName.substr(0, ++idx);
}
int LRE3SceneManager::GetObjectNumberSuffix(std::string objectName)
{
    size_t idx = objectName.find_last_not_of("1234567890");
    std::string res = objectName.substr(++idx);
    if (res == std::string(""))
        return 0;
    return std::atoi(res.c_str());
}
std::string LRE3SceneManager::GetValidObjectName(std::string objectName)
{
    if (objectPool.find(objectName) == objectPool.end())
        return objectName;
    
    std::string prefix = GetObjectNumberPrefix(objectName);
    int counter = GetObjectNumberSuffix(objectName);

    while (objectPool.find(prefix + std::to_string(++counter)) != objectPool.end());

    return prefix + std::to_string(counter);
}

std::shared_ptr<LRE3Object> LRE3SceneManager::GetObject(std::string name)
{
    return objectPool[name];
}
void LRE3SceneManager::Reparent(std::string object, std::string newParent)
{
    parentLinks[object] = newParent;
    UpdateSceneGraph();
}
std::shared_ptr<LRE3Object> LRE3SceneManager::DuplicateObject(std::shared_ptr<LRE3Object> obj, std::string parentName, bool topLevel)
{
    if (!obj) return nullptr;
    std::string newName = GetValidObjectName(obj->GetName());
    std::shared_ptr<LRE3Object> newObj = obj->Duplicate(newName);
    if (!newObj) return nullptr;
    objectPool[newName] = newObj;
    parentLinks[newName] = parentName;
    if (newObj)
        for (auto child : obj->GetChildren())
            DuplicateObject(GetObject(child->GetName()), newName, false);
    if (topLevel)
    {
        UpdateAssets();
        UpdateSceneGraph();
    }
    return newObj;
}   
void LRE3SceneManager::DeleteObject(std::shared_ptr<LRE3Object> obj, bool topLevel)
{
    if (!obj) return;
    for (auto child : obj->GetChildren())
        DeleteObject(GetObject(child->GetName()));
    objectPool.erase(obj->GetName());
    parentLinks.erase(obj->GetName());

    obj->Reparent(nullptr);
    obj->Delete();
    if (topLevel)
    {
        UpdateSceneGraph();
    }
}

void LRE3SceneManager::UpdateSceneGraph()
{
    for (auto& [name, obj]: objectPool)
    {
        std::string parentName = parentLinks[name];
        std::shared_ptr<LRE3Object> parent = std::static_pointer_cast<LRE3Object>(root);
        if (parentName.size())
            parent = objectPool[parentName];
        obj->Reparent(parent.get());
    }
}
void LRE3SceneManager::UpdateAssets()
{
    for (auto& [name, obj]: objectPool)
    {
        // obj->UpdateAssets(assets);
    }
}