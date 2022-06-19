#include"Engine.h"

#include<fstream>
#include<iostream>

//source:
//https://www.delftstack.com/howto/cpp/how-to-get-list-of-files-in-a-directory-cpp/
//https://stackoverflow.com/questions/48312460/c17-filesystem-is-not-a-namespace-name
//https://en.cppreference.com/w/cpp/experimental/fs/path
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1
#if __cplusplus < 201703L// If the version of C++ is less than 17
// It was still in the experimental:: namespace
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif
using std::experimental::filesystem::directory_iterator;


void geteverything()
{
	std::string p = "/";

	for (const auto& entry : fs::directory_iterator(fs::current_path()))
	{
		std::cout << entry.path()<<std::endl;
	}

}

void init()
{

	//std::string path = "C:\\Users\\Dimo\\Desktop\\DnD\\DnD\\DnD";

		//std::cout << "fetching all directories and files in : " << path << " ...\n";
		geteverything();


}

void Engine::run()
{
	init();

	switch (gameStage)
	{
	case stageMainMenu: gameStage = (GameStage)mainMenu->select();
		break;
	case stageCreatePlayer:
		break;
	default:
		break;
	}
}

Engine::~Engine()
{
	delete mainMenu;
}
