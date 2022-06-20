#pragma once
#include"../../Structures/Vector.h"
#include"../../Structures/Collection.h"

class Component;
class Manager;
class Entity;


class Component
{
public:
	/// <summary>
	/// ...store ptr to Entity that would have this componet
	/// </summary>
	Entity* entity;
	int type;

	/// <summary>
	/// ...init component info
	/// </summary>
	virtual void init() {}
	/// <summary>
	/// ...update component info
	/// </summary>
	virtual void update() {}
	/// <summary>
	/// draw if needed
	/// </summary>
	virtual void draw() {}
	virtual ~Component() {}
};

class Entity
{
	/// <summary>
	/// ...make communication with manager possible for both sides // used for grouping entities;
	/// </summary>
	Manager& manager;
	/// <summary>
	/// ...list for components
	/// </summary>
	Collection<Component> componentList;
	/// <summary>
	/// ...make possible to group entities
	/// </summary>
	bool groupBitSet[32] = { false };
	bool isActive = false;
public:

	Entity(Manager& m) : manager(m) { isActive = true; }

	/// <summary>
	/// call update func of components
	/// </summary>
	void update();
	/// <summary>
	/// call draw func of components
	/// </summary>
	void draw();

	/// <summary>
	/// add entity to group
	/// </summary>
	/// <param name="idOfGroup"></param>
	void addGroup(std::size_t idOfGroup);

	/// <summary>
	///  check if entity is in group
	/// </summary>
	/// <param name="idOfGroup"></param>
	/// <returns></returns>
	bool hasGroup(std::size_t idOfGroup);

	const bool getIsActive() const;
	void setIsActive(bool value);
	/// <summary>
	/// ...source for parameter packs knowage: https://en.cppreference.com/w/cpp/language/parameter_pack
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="...TArgs"></typeparam>
	/// <param name="...arguments"></param>
	/// <returns></returns>
	template<typename T, typename... TArgs>
	/// <summary>
	/// idea behind using parameter pack is to call constructors of components with parameters
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="...TArgs"></typeparam>
	/// <param name="...arguments"></param>
	/// <returns></returns>
	T& addComponent(TArgs&&... arguments);

	template<typename T>
	bool hasComponent() const;

	template<typename T>
	T& getComponent() const;
};

/// <summary>
/// ...add component to component collection
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="...TArgs"></typeparam>
/// <param name="...arguments"></param>
/// <returns></returns>
template<typename T, typename... TArgs>
T& Entity::addComponent(TArgs&&... arguments) {
	if (hasComponent<T>()) return getComponent<T>();
	T* c(new T(std::forward<TArgs>(arguments)...));
	c->entity = this;
	componentList.link_back(c);
	c->init();
	return *c;
}

/// <summary>
/// ...check if component is already added
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
bool Entity::hasComponent() const {
	Component* c = new T();
	int type = c->type;
	delete c;
	return componentList.hasComponent(type);
}

/// <summary>
/// ...get component by it's type
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
T& Entity::getComponent() const {
	if (!hasComponent<T>()) throw new std::exception("Invalid component");
	T* t = new T();
	int type = t->type;
	delete t;
	//T* ptr = *static_cast<T>(componentList.getComponent(t.type));
	return static_cast<T&>(componentList.getElement(type));
}

/// <summary>
/// ...this class create and handle all created entities
/// </summary>
class Manager
{
	Collection<Entity> entities;
	Vector<Collection<Entity>> groupedEntities;

public:

	Manager() = default;

	/// <summary>
	/// ...update all entities
	/// </summary>
	void update();
	/// <summary>
	/// draw all entites
	/// </summary>
	void draw();
	/// <summary>
	/// add entity to specific group(group entities)
	/// </summary>
	/// <param name="e"></param>
	/// <param name="idGroup"></param>
	void addToGroup(Entity* e, const size_t idGroup);

	/// <summary>
	/// get all entites of one group
	/// </summary>
	/// <param name="idGroup"></param>
	/// <returns></returns>
	Collection<Entity>& getGroup(const size_t idGroup);

	/// <summary>
	/// add entity to collection
	/// </summary>
	/// <returns></returns>
	Entity& addEntity();

	~Manager();
};