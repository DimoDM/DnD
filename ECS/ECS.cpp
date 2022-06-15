#include"ECS.h"

//Functions of entity
////////////////////////////////////////////////////////////////
void Entity::update()
{
	for (int i = 0; i < componentList.getSize(); i++) {
		componentList[i].update();
	}
}

void Entity::draw()
{
	for (int i = 0; i < componentList.getSize(); i++) {
		componentList[i].draw();
	}
}

void Entity::addGroup(std::size_t idOfGroup)
{
	groupBitSet[idOfGroup] = true;
	manager.addToGroup(this, idOfGroup);
}

bool Entity::hasGroup(std::size_t idOfGroup) {
	return groupBitSet[idOfGroup];
}

//Functions of manager
////////////////////////////////////////////////////////////////

void Manager::update() {  // update all entities
	for (int i = 0; i < entities.getSize(); i++) {
		entities[i].update();
	}
}

void Manager::draw() { // draw all entites
	for (int i = 0; i < entities.getSize(); i++) {
		entities[i].draw();
	}
}

void Manager::addToGroup(Entity* e, const size_t idGroup) { // add entity to specific group
	while (idGroup >= groupedEntities.getSize()) {
		groupedEntities.push_back(Collection<Entity>());
	}
	groupedEntities[idGroup].link_back(e);
}

Collection<Entity>& Manager::getGroup(const size_t idGroup) { // get all of entites of one group
	if (idGroup >= groupedEntities.getSize()) throw std::exception("invlaid group");
	return groupedEntities[idGroup];
}

Entity& Manager::addEntity() {   // add entity to collection

	Entity* e = new Entity(*this);
	entities.link_back(e);
	return *e;
}

Manager::~Manager() {
	for (int i = 0; i < groupedEntities.getSize(); i++) {
		int num = groupedEntities[i].getSize();
		for (int j = 0; j < num; j++) {
			groupedEntities[i].artificialPop_back(); // reduse number of elements in order to not delete them.
		}
	}
}