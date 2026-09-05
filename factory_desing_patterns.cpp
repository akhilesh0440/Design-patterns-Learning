#include <iostream>
#include <memory>

class IGameObject {
public:
	virtual ~IGameObject() {}
	virtual void update() = 0;
	virtual void render() = 0;
};

class Plane : public IGameObject {
public:
	Plane() {}
	void update() {}
	void render() {}
};

class Boat : public IGameObject {
public:
	Boat(){}
	void update() {}
	void render() {} 
};

enum class ObjectType{PLANE, BOAT};

class FactoryGameObjects{
public:
	static std::shared_ptr<IGameObject> MakeGameObjectFactory(ObjectType type) {
		if (ObjectType::PLANE == type){
			s_plane++;
			return std::make_shared<Plane>();
		}	
		else if (ObjectType::BOAT == type) {
			s_boat++;
			return std::make_shared<Boat>();
		}
		return nullptr;
	}

	static void PrintCounts() {
		std::cout << "Planes: " << s_plane << std::endl;
		std::cout << "Boats: " << s_boat << std::endl;
	}

private:
	FactoryGameObjects() {};
	~FactoryGameObjects() {};
	FactoryGameObjects(const FactoryGameObjects& o) {}

	static int s_plane;
	static int s_boat;
};

int FactoryGameObjects::s_boat = 0;
int FactoryGameObjects::s_plane = 0;

/*int main() {

	//std::shared_ptr<IGameObject> myObject = MakeGameObjectFactory(ObjectType::PLANE);
	//std::shared_ptr<IGameObject> myObject1 = MakeGameObjectFactory(ObjectType::BOAT);
	std::shared_ptr<IGameObject> myObject = FactoryGameObjects::MakeGameObjectFactory(ObjectType::PLANE);
	std::shared_ptr<IGameObject> myObject1 = FactoryGameObjects::MakeGameObjectFactory(ObjectType::BOAT);
	std::shared_ptr<IGameObject> myObject2 = FactoryGameObjects::MakeGameObjectFactory(ObjectType::BOAT);

	FactoryGameObjects::PrintCounts();

	return 0;
}*/
