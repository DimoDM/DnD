#pragma once
#include"../Structures/Vector.h"
#include"../Structures/Pointer.h"
#include"../Structures/Map.h"

class Entity; // Entity class
class Component; // Component class
class Manager; // System class that execute logic of entityes and their's components

class Component
{
public:
	Entity* entity; // store ptr to Entity that would have this componet
	const int type;

	virtual void init() {} // init component info
	virtual void update() {} // update component info
	virtual void draw() {} // draw if needed
	virtual ~Component() {}
};

class Entity
{
	Manager& manager; // make communication with manager possible for both sides;
	Vector<Pointer<Component>> componentList; // list for components
	Map<int, int> componentBitSet;
	bool groupBitSet[32] = { false }; // make possible to group entities

public :

	Entity(Manager& m) : manager(m) {}

	void update() { // call update func of components
		for (int i = 0; i < componentList.getSize(); i++) {
			componentList[i].t->update();
		}
	}
	void draw() { // call draw func of components
		for (int i = 0; i < componentList.getSize(); i++) {
			componentList[i].t->draw();
		}
	}

	void addGroup(std::size_t idOfGroup) {
		groupBitSet[idOfGroup] = true;
	}
	void delGroup(std::size_t idOfGroup) {
		groupBitSet[idOfGroup] = false;
	}
	bool hasGroup(std::size_t idOfGroup) {
		return groupBitSet[idOfGroup];
	}

	//source for parameter packs:
	//https://en.cppreference.com/w/cpp/language/parameter_pack
	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... arguments) { // idea behind that is to call constructors of components with parameters

		T* c = new T(std::forward<TArgs>(mArgs)...);
		c->entity = this;
		Pointer ptr(c);
		componentBitSet.push_back(c->type, componentList.getSize());
		componentList.push_back(ptr);
		c->init();
		return *c;
	}
	template<typename T>
	bool hasComponent() const {
		T t;
		return componentBitSet.keyIndex(t.type) != -1;
	}

	template<typename T> 
	T& getComponent() const {
		if (!hasComponent<T>()) return nullptr;
		T t;
		return componentList[componentBitSet[t.type]];
	}
};

class Manager
{
	Vector<Pointer<Entity>> entities; // collection for entityes
	Vector<Vector<Pointer<Entity>>> groupedEntities; // list of pointers to entities by groups

public:
	void update(); // update all entityes
	void draw(); //draw all entityes

	void addToGroup(Entity* e, std::size_t idOfGroup);
	Vector<Entity*>& getGroup(std::size_t idOfGroup);
	//Vector<Entity*>& getEntities(); // getList of entities
	Entity& addEntity(); // add entity to array
};


