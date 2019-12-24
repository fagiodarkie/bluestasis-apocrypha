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

    void ScreenLoader::mainMenu() const
    {
        title();
        writeOption("n", "New game");
        writeOption("l", "Load saved game");
        writeOption("x", "Exit");

        std::string choice = playerChoice();

        switch(choice[0])
        {
            case 'n': loadScreen(_chapter.screen("__start__")); break;
            case 'x': exit(0);
        }
    }

    void ScreenLoader::title() {
        std::cout << "   B L U E     S T A S I S\r\n"
                     "    - A p o c r y p h a -\r\n\r\n";
    }

    void ScreenLoader::loadScreen(chapter::Chapter::screenIterator screen) const {
        chapter::Chapter::screenIterator currentScreen = screen;
        std::string choice;

        printScreenText(currentScreen);
        while (currentScreen->lastOption() != currentScreen->firstOption())
        {
            for (auto option = currentScreen->firstOption(); option != currentScreen->lastOption(); ++option)
            {
                writeOption(option->key(), option->text());
            }

            choice = playerChoice();

            auto option = currentScreen->option(choice)->endScreen();
            currentScreen = _chapter.screen(option);
            printScreenText(currentScreen);
        }
    }

    void ScreenLoader::writeOption(const std::string &key, const std::string &text) const {
        std::cout << " [" << key << "] " << text << "\r\n";
    }

    std::string ScreenLoader::playerChoice() {
        std::string choice;
        std::cout << "\r\n\t >  " << std::flush;
        std::cin >> choice;
        return choice;
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