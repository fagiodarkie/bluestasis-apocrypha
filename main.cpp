#include <iostream>
#include "Engine/Chapter/Chapter.h"
#include "Engine/Screen/ScreenLoader.h"
#include "GameState/GameState_v1.h"

int main() {
    engine::chapter::Chapter startChapter;
    startChapter.load("..\\data\\screens_1.json");

    std::shared_ptr<gamestate::IGameState> gameState = std::make_shared<gamestate::GameState_v1>();
    engine::screen::ScreenLoader screenLoader(startChapter, gameState);

    screenLoader.mainMenu();

    return 0;
}
