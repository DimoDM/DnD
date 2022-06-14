#pragma once
#include"../Structures/Vector.h"
#include"../Structures/Map.h"
#include<exception>

class Entity; // Entity class
class Component; // Component class
class Manager; // System class that execute logic of entityes and their's components

class Component
{
public:
	Entity* entity; // store ptr to Entity that would have this componet
	int type;

	virtual void init() {} // init component info
	virtual void update() {} // update component info
	virtual void draw() {} // draw if needed
	virtual ~Component() {}
};

class Entity
{
	Manager& manager; // make communication with manager possible for both sides;
	Vector<Component*> componentList; // list for components
	Map<size_t, size_t> componentBitSet;
	bool groupBitSet[32] = { false }; // make possible to group entities

public :

	Entity(Manager& m) : manager(m) {}

	void update() { // call update func of components
		for (int i = 0; i < componentList.getSize(); i++) {
			componentList[i]->update();
		}
	}
	void draw() { // call draw func of components
		for (int i = 0; i < componentList.getSize(); i++) {
			componentList[i]->draw();
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

		T* c(new T(std::forward<TArgs>(arguments)...));
		c->entity = this;
		componentBitSet.push_back((size_t)(c->type), componentList.getSize());
		componentList.push_back(c);
		c->init();
		return *c;
	}
	template<typename T>
	bool hasComponent() const {
		T t;
		return componentBitSet.keyIndex((size_t)t.type) != -1;
	}

	template<typename T> 
	const T* getComponent() const {
		if (!hasComponent<T>()) throw new std::exception("Invalid component");
		T t;
		//size_t index = componentBitSet.keyIndex(t.type);
		return static_cast<T*>(componentList.getArray()[0]);
	}
};

class Manager
{
	Vector<Entity*> entities; // collection for entityes
	Vector<Vector<Entity*>> groupedEntities; // list of pointers to entities by groups

public:
	Manager() {
		for (int i = 0; i < 32; i++) {
			groupedEntities[i].push_back(nullptr);
		}
	}
	void update() { // update all entityes
		for (int i = 0; i < entities.getSize(); i++) {
			entities[i]->update();
		}
	}
	void draw() { //draw all entityes
		for (int i = 0; i < entities.getSize(); i++) {
			entities[i]->draw();
		}
	}

	void addToGroup(Entity* e, std::size_t idOfGroup) {
		if (&groupedEntities[idOfGroup] == nullptr) {
			Vector<Entity*> v;
			groupedEntities.push_back(v);
		}
		groupedEntities[idOfGroup].push_back(e);
	}
	Vector<Entity*>& getGroup(std::size_t idOfGroup) {
		return groupedEntities[idOfGroup];
	}
	//Vector<Entity*>& getEntities(); // getList of entities
	Entity& addEntity() { // add entity to array
		Entity* e = new Entity(*this);
		entities.push_back(e);
		return *e;
	}
};


