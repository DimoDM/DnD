#pragma once
#include"../Structures/Vector.h"
#include"../Structures/Collection.h"

class Component;
class Manager;
class Entity;


class Component
{
public:
	Entity* entity; // store ptr to Entity that would have this componet
	int type;
	virtual Component* clone() const { return new Component(*this); }
	virtual void init() {} // init component info
	virtual void update() {} // update component info
	virtual void draw() {} // draw if needed
	virtual ~Component() {}
};

class Entity
{
	Manager& manager; // make communication with manager possible for both sides // used for grouping entities;
	Collection<Component> componentList; // list for components
	bool groupBitSet[32] = { false }; // make possible to group entities

public:

	//Entity() = default;
	Entity(Manager& m) : manager(m) {}

	void update() { // call update func of components
		for (int i = 0; i < componentList.getSize(); i++) {
			componentList[i].update();
		}
	}
	void draw() { // call draw func of components
		for (int i = 0; i < componentList.getSize(); i++) {
			componentList[i].draw();
		}
	}


	void addGroup(std::size_t idOfGroup);

	bool hasGroup(std::size_t idOfGroup) {
		return groupBitSet[idOfGroup];
	}

	//source for parameter packs:
	//https://en.cppreference.com/w/cpp/language/parameter_pack
	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... arguments) { // idea behind that is to call constructors of components with parameters

		T* c(new T(std::forward<TArgs>(arguments)...));
		c->entity = this;
		componentList.link_back(c);
		c->init();
		return *c;
	}
	template<typename T>
	bool hasComponent() const {
		Component* c = new T();
		int type = c->type;
		delete c;
		return componentList.hasComponent(type);
	}

	template<typename T>
	T& getComponent() const {
		if (!hasComponent<T>()) throw new std::exception("Invalid component");
		T* t = new T();
		int type = t->type;
		delete t;
		//T* ptr = *static_cast<T>(componentList.getComponent(t.type));
		return static_cast<T&>(componentList.getElement(type));
	}
};

class Manager
{
	Collection<Entity> entities;
	Vector<Collection<Entity>> groupedEntities;

public:

	void update() {  // update all entities
		for (int i = 0; i < entities.getSize(); i++) {
			entities[i].update();
		}
	}
	void draw() { // draw all entites
		for (int i = 0; i < entities.getSize(); i++) {
			entities[i].draw();
		}
	}

	void addToGroup(Entity* e, const size_t idGroup) { // add entity to specific group
		while (idGroup >= groupedEntities.getSize()) {
			groupedEntities.push_back(Collection<Entity>());
		}
		groupedEntities[idGroup].link_back(e);
	}

	Collection<Entity>& getGroup(const size_t idGroup) { // get all of entites of one group
		if (idGroup >= groupedEntities.getSize()) throw std::exception("invlaid group");
		return groupedEntities[idGroup];
	}

	Entity& addEntity() {   // add entity to collection

		Entity* e = new Entity(*this);
		entities.link_back(e);
		return *e;
	}

	~Manager() {
		for (int i = 0; i < groupedEntities.getSize(); i++) {
			int num = groupedEntities[i].getSize();
			for (int j = 0; j < num; j++) {
				groupedEntities[i].artificialPop_back(); // reduse number of elements in order to not delete them.
			}
		}
	}
};