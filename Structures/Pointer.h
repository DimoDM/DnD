#pragma once

template<typename T>
class Pointer
{
private:
	void copyFrom(T& tmp) {
		t = new T(tmp);
	}
	void free() {
		delete t;
	}
public:
	T* t;
	Pointer(T* tmp) {
		copyFrom(tmp);
	}
	T& operator=(T& tmp) const {
		if (&t != &tmp) {
			free();
			copyFrom(tmp);
		}
		return t;
	}

	~Pointer()
};