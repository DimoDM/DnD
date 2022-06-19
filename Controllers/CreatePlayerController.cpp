#include "CreatePlayerController.h"
#include"../ECS/ECS.h"
#include"../ECS/Components.h"

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
    case 0: player->addComponent<StatsComponent>(50, 20, 30, 1, 0); break;
    case 1: player->addComponent<StatsComponent>(50, 40, 10, 1, 0); break;
    case 2: player->addComponent<StatsComponent>(50, 10, 40, 1, 0); break;
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
