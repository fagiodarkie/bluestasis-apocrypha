//
// Created by apteros on 20/12/2019.
//

#include "GameState_v1.h"
#include <filesystem>

namespace gamestate {
    const std::string gamestate::GameState_v1::FILENAME = "gamestate.json";

    GameState_v1::GameState_v1() : IGameState(1) {
        if (std::filesystem::exists(FILENAME))
            load(FILENAME);
    }

    void GameState_v1::serialisation() {
        synch("saves", _saves);
    }

    void GameState_v1::saveGame(const gamesave::save::SaveEntry &saveEntry) {

        bool existing = false;
        for (auto &save : _saves)
            if (save.getName() == saveEntry.getName()) {
                save = saveEntry;
                existing = true;
                break;
            }

        if (!existing)
            _saves.push_back(saveEntry);

        save(FILENAME);
    }

    std::vector<std::string> GameState_v1::saves() const {
        std::vector<std::string> result;
        for (auto save: _saves)
            result.push_back(save.getName());

        return result;
    }

    std::string GameState_v1::audioDirectory() const {
        return R"(..\data\music\)";
    }

    std::string GameState_v1::currentAudioFile() const
    {
        return currentAudio;
    }

    void GameState_v1::setCurrentAudioFile(const std::string& audioFile)
    {
        currentAudio = audioFile;
    }

    gamesave::save::SaveEntry GameState_v1::getSave(const std::string &saveId) const {
        for (auto save : _saves)
            if (save.getName() == saveId)
                return save;

        return *_saves.end();
    }

}