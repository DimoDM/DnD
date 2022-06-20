#pragma once
#include"ECS.h"
#include<conio.h>
#include<iostream>
#include"TransformComponent.h"
using namespace std;

/// <summary>
/// ...this component is responcible to handle keyboard input from player while playing
/// </summary>
class KeyboardComponent : public Component
{
	TransformComponent * transform;

public:
	/// <summary>
	/// ... read keyboard input and move player
	/// </summary>
	KeyboardComponent();
	void init() override;

	void update() override;

};