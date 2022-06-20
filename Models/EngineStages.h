#pragma once

enum EngineStage {
	stageMainMenu = 0,
	stageStartGame,
	stageCreatePlayer,
	stageExit
};

static EngineStage engineStage = stageMainMenu;