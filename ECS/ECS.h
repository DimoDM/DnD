#pragma once
#include"../Structures/Vector.h"

class Entity; // Entity class
class Component; // Component class
class Manager; // System class that execute logic of entityes and their's components

class Component
{
	Entity* entity; // store ptr to Entity that would have this componet

	virtual void init() {} // init component info
	virtual void update() {} // update component info
	virtual void draw() {} // draw if needed
	virtual ~Component() {}
};

class Entity
{
	Manager& manager; // make communication with manager possible for both sides;
	Vector<Component*> componentList; // list for components
	bool groupBitSet[32] = { false }; // make possible to group entities

public :

	Entity(Manager& m) : manager(m) {}

	void update(); // call update func of components

	void addGroup(std::size_t idOfGroup);
	void delGroup(std::size_t idOfGroup);
	bool hasGroup(std::size_t idOfGroup);

	//source for parameter packs:
	//https://en.cppreference.com/w/cpp/language/parameter_pack
	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... arguments); // idea behind that is to call constructors of components with parameters
	template<typename T>
	bool hasComponent() const;

	template<typename T> 
	T& getComponent() const;
};

class Manager
{
	Vector<Entity*> entities; // collection for entityes
	Vector<Vector<Entity*>> groupedEntities; // list of pointers to entities by groups

public:
	void update(); // update all entityes
	void draw(); //draw all entityes

	void addToGroup(Entity* e, std::size_t idOfGroup);
	//Vector<Entity*>& getEntities(); // getList of entities
	Entity& addEntity(); // add entity to array
};


