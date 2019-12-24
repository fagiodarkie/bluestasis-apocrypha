//
// Created by apteros on 12/12/2019.
//

#include "ScreenLoader.h"
#include "ScreenUtils.h"
#include "../Chapter/Chapter.h"

#include <iostream>
#include <iomanip>

namespace engine::screen {

    ScreenLoader::ScreenLoader(const chapter::Chapter& chapter) : _chapter(chapter) {}

    void ScreenLoader::loadScreen(chapter::Chapter::screenIterator screen) const {
        chapter::Chapter::screenIterator currentScreen = screen;
        std::string choice;

        printScreenText(currentScreen);
        while (currentScreen->lastOption() != currentScreen->firstOption())
        {
            for (auto option = currentScreen->firstOption(); option != currentScreen->lastOption(); ++option)
            {
                std::cout << " [" << option->key() << "] " << option->text() << "\r\n";
            }

            std::cout << "\r\n\t >  " << std::flush;

            std::cin >> choice;

            auto option = currentScreen->option(choice)->endScreen();
            currentScreen = _chapter.screen(option);
            printScreenText(currentScreen);
        }
    }

    void ScreenLoader::printScreenText(chapter::Chapter::screenIterator  screen) const {
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
}