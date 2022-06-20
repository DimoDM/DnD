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
	bool isActive = false;
public:

	//Entity() = default;
	Entity(Manager& m) : manager(m) { isActive = true; }

	void update(); // call update func of components
	void draw(); // call draw func of components

	void addGroup(std::size_t idOfGroup); // add entity to group

	bool hasGroup(std::size_t idOfGroup); // check if entity is in group

	const bool getIsActive() const;
	void setIsActive(bool value);
	//source for parameter packs:
	//https://en.cppreference.com/w/cpp/language/parameter_pack
	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... arguments); // idea behind that is to call constructors of components with parameters

	template<typename T>
	bool hasComponent() const;

	template<typename T>
	T& getComponent() const;
};

template<typename T, typename... TArgs>
T& Entity::addComponent(TArgs&&... arguments) { // idea behind that is to call constructors of components with parameters
	if (hasComponent<T>()) return getComponent<T>();
	T* c(new T(std::forward<TArgs>(arguments)...));
	c->entity = this;
	componentList.link_back(c);
	c->init();
	return *c;
}

template<typename T>
bool Entity::hasComponent() const {
	Component* c = new T();
	int type = c->type;
	delete c;
	return componentList.hasComponent(type);
}

template<typename T>
T& Entity::getComponent() const {
	if (!hasComponent<T>()) throw new std::exception("Invalid component");
	T* t = new T();
	int type = t->type;
	delete t;
	//T* ptr = *static_cast<T>(componentList.getComponent(t.type));
	return static_cast<T&>(componentList.getElement(type));
}

class Manager
{
	Collection<Entity> entities;
	Vector<Collection<Entity>> groupedEntities;

public:

	Manager() = default;

	void update();  // update all entities
	void draw(); // draw all entites
	void addToGroup(Entity* e, const size_t idGroup); // add entity to specific group

	Collection<Entity>& getGroup(const size_t idGroup); // get all entites of one group
	Entity& addEntity();   // add entity to collection

	~Manager();
};