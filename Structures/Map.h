#pragma once
#include"Pair.h"
#include"Vector.h"
#include<exception>

//lazy and dump way to do map
template<typename T, typename D>
class Map
{
	Vector<Pair<T, D>> data;

public:
	void push_back(Pair<T, D>);
	void push_back(T first, D second);
	const std::size_t keyIndex(T& key) const;
	D& operator[](T& key);
};

template<typename T, typename D>
void Map<T, D>::push_back(Pair<T, D> pair)
{
	data.push_back(pair);
}
template<typename T, typename D>
void Map<T, D>::push_back(T first, D second)
{
	Pair<T, D> pair(first, second);
	data.push_back(pair);
}

template<typename T, typename D>
const std::size_t Map<T, D>::keyIndex(T& key) const
{
	for (int i = 0; i < data.size; i++) {
		if (key == data[i].getFirst()) return i;
	}
	return -1;
}

template<typename T, typename D>
D& Map<T, D>::operator[](T& key)
{
	std::size_t index = keyIndex(key);
	if (index == -1) throw new std::exception("InvalidKey");
	return data[index].getSecond();
}
