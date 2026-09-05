#include <iostream>	


class IGameObject {
public:
	virtual ~IGameObject() {}
	virtual void ObjectPlayDefaultAnimation() = 0;
	virtual void ObjectMoveInGame() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};

class Plane : public IGameObject {
public:
	Plane(int x, int y) {
		ObjectsCreated++;
	}
	void ObjectPlayDefaultAnimation() {};
	void ObjectMoveInGame() {};
	void update() {}
	void render() {}
	static IGameObject* Create() {
		return new Plane(0, 0);
	}

private:
	static int ObjectsCreated;
};

class Boat : public IGameObject {
public:
	Boat(int x, int y) {}
	void ObjectPlayDefaultAnimation() {};
	void ObjectMoveInGame() {};
	void update() {}
	void render() {}
	static IGameObject* Create() {
		return new Boat(0, 0);
	}
};

class Ant : public IGameObject {
public:
	Ant(int x, int y) {
		ObjectsCreated++;
	}

	void ObjectPlayDefaultAnimation() {};
	void ObjectMoveInGame() {};
	void update() {}
	void render() {}
	static IGameObject* Create() {
		return new Ant(0, 0);
	}

private:
	static int ObjectsCreated;
};