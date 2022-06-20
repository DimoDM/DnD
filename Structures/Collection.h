#pragma once

template<typename T>
class Collection
{
	T** components;
	size_t capacity;
	size_t size;

	/// <summary>
	/// ...delete all objects in collection
	/// </summary>
	void free();
	void copyFrom(const Collection& other);
	void resize();

public:
	/// <summary>
	/// default constructor
	/// </summary>
	Collection();
	/// <summary>
	/// copy constructor
	/// </summary>
	/// <param name="other"></param>
	Collection(const Collection& other);
	/// <summary>
	/// operator=
	/// </summary>
	/// <param name="c"></param>
	/// <returns></returns>
	Collection& operator=(const Collection& c);
	/// <summary>
	/// ...add element to collection. Used type must have clone funtion.
	/// </summary>
	/// <param name="c"></param>
	void addElement(const T* c);
	/// <summary>
	/// ...Warning!!! Add element to collection with same existing item (shadow copy).
	/// </summary>
	/// <param name="c"></param>
	void link_back(T* c);
	/// <summary>
	/// ...reduse size by one. Use only if you have two collections with same pointers(in order to not delete one element two times)!!!
	/// </summary>
	void artificialPop_back();
	/// <summary>
	/// ...get element by type. Use only for objects that have variable 'type' in them!!!
	/// </summary>
	/// <param name="type"></param>
	/// <returns></returns>
	T& getElement(size_t type) const;
	T& operator[](size_t index);
	T* getElementByIndex(size_t index);
	void pop_id(size_t index);
	void deleteElement(T& element);
	/// <summary>
	/// use only for Component objects or that which have variable 'type' in them!
	/// </summary>
	/// <param name="type"></param>
	/// <returns></returns>
	const bool hasComponent(size_t type) const;

	/// <summary>
	/// return number of objects in collection
	/// </summary>
	/// <returns></returns>
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
		components[i] = other.components[i];
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
void Collection<T>::addElement(const T* c)
{
	if (size == capacity)
		resize();
	components[size++] = c->clone();
}

template<typename T>
void Collection<T>::link_back(T* c)
{
	if (size == capacity)
		resize();
	//std::cout << c << " ";
	components[size++] = c;
	//std::cout << components[size - 1] << std::endl;
}

template<typename T>
void Collection<T>::artificialPop_back()
{
	size--;
}

template<typename T>
T& Collection<T>::getElement(size_t type) const
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
	return static_cast<T&>(*components[index]);
}

template<typename T>
inline T* Collection<T>::getElementByIndex(size_t index)
{
	if (index < 0 || index >= size) throw new std::exception("out of bounds");
	return static_cast<T*>(components[index]);
}

template<typename T>
void Collection<T>::pop_id(size_t index)
{
	components[index] = components[size - 1];
	delete components[size - 1];
}

template<typename T>
void Collection<T>::deleteElement(T& element)
{
	for (int i = 0; i < size; i++) {
		if (&*components[i] == &element) {
			pop_id(i);
			return;
		}
	}
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

/// <summary>
/// delete all objects in collection/ handle with dyn arrays in collection
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
Collection<T>::~Collection()
{
	free();
}
