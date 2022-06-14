#include "Entity.h"

void ComponentCollection::free()
{
	for (size_t i = 0; i < size; i++)
		delete components[i];
	delete[] components;
}

void ComponentCollection::copyFrom(const ComponentCollection& other)
{
	components = new Component * [other.capacity];
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < size; i++)
	{
		components[i] = other.components[i]->clone();
	}
}

void ComponentCollection::resize()
{
	Component** newCollection = new Component * [capacity *= 2];
	for (size_t i = 0; i < size; i++)
		newCollection[i] = components[i];
	delete[] components;
	components = newCollection;
}

ComponentCollection::ComponentCollection()
{
	capacity = 8;
	size = 0;
	components = new Component * [capacity];
}

ComponentCollection::ComponentCollection(const ComponentCollection& other)
{
	copyFrom(other);
}

ComponentCollection& ComponentCollection::operator=(const ComponentCollection& c)
{
	if (this != &c)
	{
		free();
		copyFrom(c);
	}
	return *this;
}

void ComponentCollection::addComponent(const Component* c)
{
	if (size == capacity)
		resize();
	components[size++] = c->clone();
}

void ComponentCollection::push_back(Component* c)
{
	if (size == capacity)
		resize();
	std::cout << c << " ";
	components[size++] = c;
	std::cout << components[size - 1] << std::endl;
}

Component& ComponentCollection::getComponent(size_t type) const
{
	for (size_t i = 0; i < size; i++) {
		if (components[i]->type == type) return *components[i];
	}
	throw new std::exception("invalid component");
}

Component& ComponentCollection::operator[](size_t index)
{
	if (index < 0 || index >= size) throw new std::exception("out of bounds");
	return *components[index];
}

const bool ComponentCollection::hasComponent(size_t type) const
{
	for (size_t i = 0; i < size; i++) {
		if (components[i]->type == type) return true;
	}
	return false;
}

const size_t ComponentCollection::getSize() const
{
	return size;
}

ComponentCollection::~ComponentCollection()
{
	free();
}
