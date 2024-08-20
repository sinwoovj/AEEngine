#include "Registry.h"
#include "TransformComp.h"
Registry* Registry::ptr = nullptr;

Registry::Registry()
{
    //Register ALL the functions
    //rttiMap.insert(std::pair<std::string, BaseRTTI * (*)()>("TransformComp", &TransformComp::CreateTransformComp));
    rttiMap.insert({ TransformComp::TransformTypeName, &TransformComp::CreateTransformComp });
    
}

Registry::~Registry()
{
}

Registry* Registry::GetPtr()
{
    if (ptr == nullptr)
        ptr = new Registry;
    return ptr;
}

void Registry::Delete()
{
    if (ptr != nullptr)
        delete ptr;

    ptr = nullptr;
}

BaseRTTI* Registry::FindAndCreate(const std::string& type)
{
    //find
    if (rttiMap.find(type) == rttiMap.end())
    {
        return nullptr;
    }
    return rttiMap.find(type)->second();
}
