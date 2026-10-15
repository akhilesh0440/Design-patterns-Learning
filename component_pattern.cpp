#include <iostream>
#include <map>

enum class ComponentType
{
    TEXTURE,
    COLLISION,
    POSITION
};

// Interface
struct IComponent
{
    virtual void Update() = 0;           // Must be implemented
    virtual ComponentType GetType() = 0; // Mus be Implementd
};

struct TextureComponent : public IComponent
{
    void Update() { std::cout << "TexutreComponent::Update" << std::endl; }
    ComponentType GetType() { return ComponentType::TEXTURE; }
};

struct CollisionComponent : public IComponent
{
    void Update() { std::cout << "CollisionComponent::Update" << std::endl; }
    ComponentType GetType() { return ComponentType::COLLISION; }
};

struct PositionComponent : public IComponent
{
    void Update() { std::cout << "PositionComponent::Update" << std::endl; }
    ComponentType GetType() { return ComponentType::POSITION; }
};

struct GameObject
{

    void Update()
    {
        for (auto &[key, vlaue] : mComponents)
        {
            mComponents[key]->Update();
        }
    }

    // May consider using 'unique_ptr for components'
    void AddComponent(IComponent *c)
    {
        mComponents[c->GetType()] = c;
    }

    IComponent *GetComponentType(ComponentType type)
    {
        auto found = mComponents.find(type);
        if (found != mComponents.end())
        {
            return found->second;
        }
        return nullptr;
    }

    std::map<ComponentType, IComponent *> mComponents;
};

int main()
{
    GameObject mario;
    TextureComponent tc;
    PositionComponent pc;
    CollisionComponent cc;
    mario.AddComponent(&tc);
    mario.AddComponent(&pc);
    mario.AddComponent(&cc);

    auto retrieveComponent = mario.GetComponentType(ComponentType::TEXTURE);
    retrieveComponent->Update();

    mario.Update();

    return 0;
}