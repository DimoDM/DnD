#pragma once

enum GameStage {
	stageMainMenu = 0,
	stageStartGame,
	stageCreatePlayer,
	stageExit
};

static GameStage gameStage = stageMainMenu;