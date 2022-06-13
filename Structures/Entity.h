#pragma once
#include"Component.h"
#include"Manager.h"
#include"../Structures/Vector.h"
#include"../Structures/Pointer.h"

class Entity
{
	Manager& manager; // make communication with manager possible for both sides;
	Vector<Pointer<Component>> componentList; // list for components
	bool groupBitSet[32] = { false }; // make possible to group entities

public:

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

	void addGroup(std::size_t idOfGroup);
	void delGroup(std::size_t idOfGroup);
	const bool hasGroup(std::size_t idOfGroup) const;

	//source for parameter packs:
	//https://en.cppreference.com/w/cpp/language/parameter_pack
	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... arguments); // idea behind that is to call constructors of components with parameters
	template<typename T>
	bool hasComponent() const;

	template<typename T>
	T& getComponent() const;
};