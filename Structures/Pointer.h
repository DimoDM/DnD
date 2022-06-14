#pragma once

template<typename T>
class Pointer
{
private:

public:
	T* t;
	Pointer() {
		t = nullptr;
	}
	Pointer(T* tmp) {
		t = tmp;
	}
	T& operator=(T& tmp) const {
		t = tmp;
		return t;
	}

	~Pointer() {}
};