#pragma once

template<typename T>
class Collection
{
	T** components;
	size_t capacity;
	size_t size;

	void free();
	void copyFrom(const Collection& other);
	void resize();

public:
	Collection();
	Collection(const Collection& other);
	Collection& operator=(const Collection& c);
	void addComponent(const T* c);
	void push_back(T* c);
	T& getComponent(size_t type) const;
	T& operator[](size_t index);
	const bool hasComponent(size_t type) const;

	const size_t getSize() const;

	~Collection();

};

template<typename T>
void Collection<T>::free()
{
	for (size_t i = 0; i < size; i++)
		delete components[i];
	delete[] components;
}

template<typename T>
void Collection<T>::copyFrom(const Collection& other)
{
	components = new T * [other.capacity];
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < size; i++)
	{
		components[i] = other.components[i]->clone();
	}
}

template<typename T>
void Collection<T>::resize()
{
	T** newCollection = new T * [capacity *= 2];
	for (size_t i = 0; i < size; i++)
		newCollection[i] = components[i];
	delete[] components;
	components = newCollection;
}

template<typename T>
Collection<T>::Collection()
{
	capacity = 8;
	size = 0;
	components = new T * [capacity];
}

template<typename T>
Collection<T>::Collection(const Collection& other)
{
	copyFrom(other);
}

template<typename T>
Collection<T>& Collection<T>::operator=(const Collection& c)
{
	if (this != &c)
	{
		free();
		copyFrom(c);
	}
	return *this;
}

template<typename T>
void Collection<T>::addComponent(const T* c)
{
	if (size == capacity)
		resize();
	components[size++] = c->clone();
}

template<typename T>
void Collection<T>::push_back(T* c)
{
	if (size == capacity)
		resize();
	//std::cout << c << " ";
	components[size++] = c;
	//std::cout << components[size - 1] << std::endl;
}

template<typename T>
T& Collection<T>::getComponent(size_t type) const
{
	for (size_t i = 0; i < size; i++) {
		if (components[i]->type == type) return *components[i];
	}
	throw new std::exception("invalid component");
}

template<typename T>
T& Collection<T>::operator[](size_t index)
{
	if (index < 0 || index >= size) throw new std::exception("out of bounds");
	return *components[index];
}

template<typename T>
const bool Collection<T>::hasComponent(size_t type) const
{
	for (size_t i = 0; i < size; i++) {
		if (components[i]->type == type) return true;
	}
	return false;
}

template<typename T>
const size_t Collection<T>::getSize() const
{
	return size;
}

template<typename T>
Collection<T>::~Collection()
{
	free();
}
