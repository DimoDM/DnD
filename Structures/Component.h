#pragma once
#include"Entity.h"
class Component
{
public:
	Entity* entity; // store ptr to Entity that would have this componet

	virtual void init() = 0; // init component info
	virtual void update() {} // update component info
	virtual void draw() {} // draw if needed
	virtual ~Component() {}
};