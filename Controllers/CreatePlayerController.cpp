#include "CreatePlayerController.h"
#include"../ECS/ECS.h"
#include"../ECS/Components.h"
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


const bool CreatePlayerController::isValidName(const char* name) const
{
//TDOD
    return true;
}

void CreatePlayerController::createPlayer()
{
    Manager m;
    Entity* player = new Entity(m);
    player->addComponent<TransformComponent>(1, 0);
    player->addComponent<SpriteComponent>();
    player->addComponent<InventoryComponent>();

    int race = raceMenu->select();
    switch (race)
    {
    case 0: player->addComponent<StatsComponent>(30, 20, 50); break;
    case 1: player->addComponent<StatsComponent>(10, 40, 50); break;
    case 2: player->addComponent<StatsComponent>(40, 10, 50); break;
    default: player->addComponent<StatsComponent>(); break;
    }

    viewer->print("Enter name: ");
    viewer->print();

    String name;
    std::cin >> name;
    player->addComponent<PlayerComponent>(name.c_str());
    player->addComponent<SaveLoadComponent>();
    player->getComponent<SaveLoadComponent>().save();

    delete player;
}


CreatePlayerController::CreatePlayerController(ConsoleViewer* consoleViewer)
{
    viewer = consoleViewer;
}
