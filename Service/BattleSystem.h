#pragma once
#include"../Models/ECS/ECS.h"
#include"../Structures/Collection.h"

/// <summary>
/// this class execute logic for battle phase
/// </summary>
class BattleSystem
{
	/// <summary>
	/// pointers to existing collection
	/// </summary>
	Collection<Entity>* players;
	/// <summary>
	/// pointers to existing collection
	/// </summary>
	Collection<Entity>* monsters;

	/// <summary>
	/// pointers to existing entities
	/// </summary>
	Entity* player = nullptr;
	/// <summary>
	/// pointers to existing entities
	/// </summary>
	Entity* monster = nullptr;

	bool playerMove = true;

public:

	/// <summary>
	/// ...load collections with players and monsters
	/// </summary>
	/// <param name="ps"></param>
	/// <param name="ms"></param>
	BattleSystem(Collection<Entity>& ps, Collection<Entity>& ms);

	/// <summary>
	/// do battle logic and return value for the result
	/// </summary>
	/// <returns></returns>
	int battle();

private:
	/// <summary>
	/// check if battle is ready to start
	/// </summary>
	/// <returns></returns>
	bool listenForBattle();
	/// <summary>
	/// do battle logic and return value for the result
	/// </summary>
	/// <returns></returns>
	int update();
	/// <summary>
	/// update components needed for battle and do battle logic, return monster dealed damage
	/// </summary>
	void draw();
};