#pragma once
#include"ECS.h"
#include"../../Structures/String.h"

/// <summary>
/// Storage name of player
/// </summary>
class PlayerComponent : public Component
{
	String name = "Player";

public:

	PlayerComponent();

	PlayerComponent(const char* name);

	/// <summary>
	/// get name of player
	/// </summary>
	/// <returns></returns>
	const char* getName() const;


};