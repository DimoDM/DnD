#include"SaveLoadComponent.h"
#include<fstream>
#include<iostream>
#include"../Structures/FileManager.h"

//source:
//https://www.delftstack.com/howto/cpp/how-to-get-list-of-files-in-a-directory-cpp/
//https://stackoverflow.com/questions/48312460/c17-filesystem-is-not-a-namespace-name
//https://en.cppreference.com/w/cpp/experimental/fs/path
//#include <experimental\filesystem>
//
//using experimental::filesystem::directory_iterator;

SaveLoadComponent::SaveLoadComponent() : Component() {
	type = 10;
}

void SaveLoadComponent::init()
{
	transform = &entity->getComponent<TransformComponent>();
	sprite = &entity->getComponent<SpriteComponent>();
	inventory = &entity->getComponent<InventoryComponent>();
	stats = &entity->getComponent<StatsComponent>();
	player = &entity->getComponent<PlayerComponent>();

	//String path = "/";
	//for (const auto& file : directory_iterator()) {
	//	std::cout<<file.path()<<std::endl;
	//}
}

void SaveLoadComponent::save()
{
	std::ofstream file;
	String name = player->getName();
	name += ".txt";
	FileManager::openFile(file, name.c_str(), ios::binary);
}
