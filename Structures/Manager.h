#pragma once
#include"Entity.h"
#include"Component.h"
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
