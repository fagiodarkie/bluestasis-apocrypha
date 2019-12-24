//
// Created by apteros on 12/12/2019.
//

#include "ScreenLoader.h"
#include "ScreenUtils.h"
#include "../Chapter/Chapter.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>

namespace engine::screen {

    ScreenLoader::ScreenLoader(const chapter::Chapter& chapter, std::shared_ptr<gamestate::IGameState> gameState)
    : _chapter(chapter), _gameState(gameState) {}

    void ScreenLoader::loadScreen(chapter::Chapter::screenIterator screen) const {
        auto currentScreen = screen;
        std::string choice;

        printScreenText(currentScreen);
        while (currentScreen->lastOption() != currentScreen->firstOption())
        {
            for (auto option = currentScreen->firstOption(); option != currentScreen->lastOption(); ++option)
            {
                writeOption(option->key(), option->text());
            }
            for (const auto & option : reservedOptions)
                writeOption(option.first, option.second);

            std::cout << "\r\n\t >  " << std::flush;

            std::cin >> choice;

            if (selectedOptionIsReserved(choice))
            {
                processReservedOption(choice, currentScreen->id());
            }
            else {
                auto option = currentScreen->option(choice)->endScreen();
                currentScreen = _chapter.screen(option);
                printScreenText(currentScreen);
            }
        }
    }

    void ScreenLoader::printScreenText(chapter::Chapter::screenIterator  screen) {
        utils::ClearScreen();
        std::cout << "\r\n\t" << screen->title() << "\r\n\r\n" << screen->text() << "\r\n\r\n";
    }

    void ScreenLoader::writeOption(const std::string &key, const std::string &text) {
        std::cout << " [" << key << "] " << text << "\r\n";
    }

    bool ScreenLoader::selectedOptionIsReserved(const std::string &selectedKey) const {
        return reservedOptions.find(selectedKey) != reservedOptions.end();
    }

    void ScreenLoader::saveGame(const std::string &screenId, const std::string &name) const {
        auto save = gamesave::save::SaveEntry(name, _chapter.id(), screenId);
        _gameState->saveGame(save);
    }

    void ScreenLoader::processReservedOption(const std::string &option, const std::string &screenId) const {
        if (option == "s")
        {
            std::string saveName;
            std::cout << "Insert new save name: " << std::endl;
            std::cin >> saveName;
            saveGame(screenId, saveName);
        }
    }

    void ScreenLoader::exit() const {

    }
}