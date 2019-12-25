//
// Created by apteros on 12/12/2019.
//

#include "ScreenLoader.h"
#include "ScreenUtils.h"
#include "../Chapter/Chapter.h"
#include "../../GameState/GameState_v1.h"
#include <filesystem>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>

namespace engine::screen {

    const std::map<std::string, std::string> ScreenLoader::reservedOptions = {
            {"S", "Save"},
            {"M", "To Main Menu"},
            {"X", "Exit"}
    };

    const std::map<std::string, std::string> ScreenLoader::mainMenuOptions = {
            {"N", "New Game"},
            {"L", "Load"},
            {"X", "Exit"}
    };


    ScreenLoader::ScreenLoader(const chapter::Chapter& chapter, std::shared_ptr<gamestate::IGameState> gameState)
    : _chapter(chapter), _gameState(gameState) {}

    void ScreenLoader::mainMenu() const
    {
        std::string choice;
        screenAudio("Menu.wav");
        title();
        do {
            for (const auto& option: mainMenuOptions)
                writeOption(option.first, option.second);

            choice = playerChoice();

            switch(choice[0])
            {
                case 'N': loadScreen(_chapter.screen("__start__")); break;
                case 'L': loadGame(); break;
                case 'X': exit();
                default: choice = "";
            }
        }
        while (choice.empty());
    }

    void ScreenLoader::title()
    {
        std::cout << "\r\n   B L U E     S T A S I S\r\n"
                        "    - A p o c r y p h a -\r\n\r\n";
    }

    void ScreenLoader::loadScreen(chapter::Chapter::screenIterator screen) const
    {
        auto currentScreen = screen;
        std::string choice;

        printScreenText(currentScreen);
        screenAudio(currentScreen->sound());
        while (currentScreen->lastOption() != currentScreen->firstOption())
        {
            for (auto option = currentScreen->firstOption(); option != currentScreen->lastOption(); ++option)
                writeOption(option->key(), option->text());
            for (const auto & option : reservedOptions)
                writeOption(option.first, option.second);

            choice = playerChoice();

            if (selectedOptionIsReserved(choice))
            {
                processReservedOption(choice, currentScreen->id());
            }
            else if (currentScreen->option(choice) != currentScreen->lastOption())
            {
                auto option = currentScreen->option(choice)->endScreen();
                currentScreen = _chapter.screen(option);
                printScreenText(currentScreen);
                screenAudio(currentScreen->sound());
                choice = "";
            }
        }
    }

    void ScreenLoader::writeOption(const std::string &key, const std::string &text) const
    {
        std::cout << " [" << key << "] " << text << "\r\n";
    }

    void ScreenLoader::screenAudio(const std::string &audioFile) const
    {
        if (_gameState->version() < 1)
            return;

        auto audioGameState = dynamic_cast<gamestate::GameState_v1*>(_gameState.get());
        if (audioGameState->currentAudioFile() == audioFile)
            return;

        audioGameState->setCurrentAudioFile(audioFile);
        std::string musicFile = audioGameState->audioDirectory() + audioFile;
        if (std::filesystem::exists(musicFile))
        {
            PlaySound(TEXT(musicFile.c_str()), NULL, SND_FILENAME | SND_ASYNC);
        }
    }

    std::string ScreenLoader::playerChoice()
    {
        std::string choice;
        std::cout << "\r\n\t >" << std::flush;
        std::cin >> choice;
        return choice;
    }

    void ScreenLoader::loadGame() const
    {
        std::cout << "LOAD GAME\r\n" << std::endl;

        auto saveNames = _gameState->saves();
        std::string choice;
        do {
            if (!choice.empty()) // player already tried to select a choice and got it wrong.
                std::cout << "Please write the name of the desired load slot, minding the case sensitiveness.\r\n" << std::endl;

            for (auto saveName: saveNames)
                writeOption(saveName, _chapter.screen(_gameState->getSave(saveName).getScreenKey())->title());

            choice = playerChoice();
        }
        while(std::find(saveNames.begin(), saveNames.end(), choice) == saveNames.end());
        auto screenChosen = _chapter.screen(_gameState->getSave(choice).getScreenKey());
        loadScreen(screenChosen);
    }

    void ScreenLoader::printScreenText(chapter::Chapter::screenIterator  screen)
    {
        utils::ClearScreen();
        std::cout << "\r\n\t" << screen->title() << "\r\n\r\n";
        auto text = screen->text();
        while (text.size() > 80)
        {
            int lastSpace = text.substr(0, 80).find_last_of(' ');
            auto chunk = text.substr(0, lastSpace);
            std::cout << chunk << std::endl;
            text = text.substr(lastSpace + 1);
        }
        if (!text.empty())
            std::cout << text << std::endl;

        std::cout << std::endl;
    }

    bool ScreenLoader::selectedOptionIsReserved(const std::string &selectedKey) const
    {
        return reservedOptions.find(selectedKey) != reservedOptions.end();
    }

    void ScreenLoader::saveGame(const std::string &screenId, const std::string &name) const
    {
        auto save = gamesave::save::SaveEntry(name, _chapter.id(), screenId);
        _gameState->saveGame(save);
    }

    void ScreenLoader::processReservedOption(const std::string &option, const std::string &screenId) const
    {
        switch(option[0]) {
            case 'S': {
                std::string saveName;
                std::cout << "Insert new save name: " << std::endl;
                std::cin >> saveName;
                saveGame(screenId, saveName);
                break;
            }
            case 'M': mainMenu(); break;
            case 'X': exit();
        }

    }

    void ScreenLoader::exit() const
    {
        ::exit(0);
    }
}