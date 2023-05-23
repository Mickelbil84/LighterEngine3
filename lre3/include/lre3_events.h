#pragma once

#include <vector>

enum LRE3EventType
{
    LRE3_EVENT_OBJECT_INIT,
    LRE3_EVENT_OBJECT_UPDATE,

    LRE3_EVENT_OBJECT_REORDER,
};

template <typename T>
class LRE3Observer
{
public:
    virtual void OnNotify(T* sender, LRE3EventType eventType) = 0;
};

template <typename T>
class LRE3Subject
{
public:
    void AddObserver(LRE3Observer<T>* observer)
    {
        m_observers.push_back(observer);
    }
    void RemoveObserver(LRE3Observer<T>* observer)
    {   
        std::erase(m_observers, observer);
    }
    void Notify(T* sender, LRE3EventType eventType)
    {
        for (auto observer : m_observers)
            observer->OnNotify(sender, eventType);
    }

protected:
    std::vector<LRE3Observer<T>*> m_observers;
};