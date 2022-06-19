#pragma once

enum GameStage {
	stageMainMenu = 0,
	stageCreatePlayer,
	stageExit
};

static GameStage gameStage = stageMainMenu;