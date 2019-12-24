//
// Created by apteros on 20/12/2019.
//

#include "GameState_v1.h"
#include <filesystem>

const std::string gamestate::GameState_v1::FILENAME = "gamestate.json";

gamestate::GameState_v1::GameState_v1() : IGameState(1) {
    if (std::filesystem::exists(FILENAME))
        load(FILENAME);
}

void gamestate::GameState_v1::serialisation() {
    synch("saves", _saves);
}

void gamestate::GameState_v1::saveGame(const gamesave::save::SaveEntry &saveEntry) {

    bool existing = false;
    for (auto & save : _saves)
        if (save.getName() == saveEntry.getName())
        {
            save = saveEntry;
            existing = true;
            break;
        }

    if (!existing)
        _saves.push_back(saveEntry);

    save(FILENAME);
}

std::vector<std::string> gamestate::GameState_v1::saves() const {
    std::vector<std::string> result;
    for (auto save: _saves)
        result.push_back(save.getName());

    return result;
}

gamesave::save::SaveEntry gamestate::GameState_v1::getSave(const std::string &saveId) const {
    for (auto save : _saves)
        if (save.getName() == saveId)
            return save;

    throw 3;
}

