#pragma once
#include"../Structures/Vector.h"
#include"../Structures/Collection.h"
#include<iostream>
class Component;
class ComponentCollection;
class Entity;
class Manager;

class ComponentCollection
{
	Component** components;
	size_t capacity;
	size_t size;

	void free();
	void copyFrom(const ComponentCollection& other);
	void resize();

public:
	ComponentCollection();
	ComponentCollection(const ComponentCollection& other);
	ComponentCollection& operator=(const ComponentCollection& c);
	void addComponent(const Component* c);
	void push_back(Component* c);
	Component& getComponent(size_t type) const;
	Component& operator[](size_t index);
	const bool hasComponent(size_t type) const;

	const size_t getSize() const;

	~ComponentCollection();

};



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
	Manager& manager; // make communication with manager possible for both sides // used for groupin entities;
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
		std::cout << c << " ";
		componentList.link_back(c);
		c->init();
		std::cout << c->type << std::endl;
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
		std::cout << "type: " << type << " " << &static_cast<T&>(componentList.getElement(type)) << std::endl;
		return static_cast<T&>(componentList.getElement(type));
	}
};

class Manager
{
	Collection<Entity> entities;
	Vector<Collection<Entity>> groupedEntities;

public:

	void update();
	void draw();

	void addToGroup(Entity* e, const size_t idGroup);

	Collection<Entity>& getGroup(const size_t idGroup);

	Entity& addEntity();
};