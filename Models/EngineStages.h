#pragma once

/// <summary>
/// ...stages of game
/// </summary>
enum EngineStage {
	stageMainMenu = 0,
	stageStartGame,
	stageCreatePlayer,
	stageExit
};

static EngineStage engineStage = stageMainMenu;