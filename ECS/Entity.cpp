#include "Entity.h"

void ComponentCollection::free()
{
	for (size_t i = 0; i < size; i++)
		delete components[i];
	delete[] components;
}
