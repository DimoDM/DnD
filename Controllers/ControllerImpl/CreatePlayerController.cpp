#include "../CreatePlayerController.h"
#include"../../Models/ECS/ECS.h"
#include"../../Models/ECS/Components.h"

/// <summary>
/// initialize player parameters and save them to file
/// </summary>
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
    case 0: player->addComponent<StatsComponent>(50, 20, 30, 1, 0, 1); break;
    case 1: player->addComponent<StatsComponent>(50, 40, 10, 1, 0, 1); break;
    case 2: player->addComponent<StatsComponent>(50, 10, 40, 1, 0, 1); break;
    default: player->addComponent<StatsComponent>(); break;
    }

    viewer->print("Enter name: ");
    viewer->print();

    String name;
    std::cin >> name;
    player->addComponent<PlayerComponent>(name.c_str());
    player->addComponent<SaveInFileComponent>();
    player->getComponent<SaveInFileComponent>().save();

    delete player;
}


CreatePlayerController::CreatePlayerController(ConsoleViewer* consoleViewer)
{
    viewer = consoleViewer;
}
