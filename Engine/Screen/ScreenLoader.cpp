//
// Created by apteros on 12/12/2019.
//

#include "ScreenLoader.h"
#include "ScreenUtils.h"

#include <iostream>
#include <iomanip>

namespace engine::screen {
    ScreenLoader::ScreenLoader() {}

    void ScreenLoader::loadScreen(const Screen & screen) const {
        utils::ClearScreen();
        std::cout << "/r/n/t" << screen.title() << "/r/n/r/n" << screen.text() << "/r/n/r/n";

        for (auto option = screen.firstOption(); option != screen.lastOption(); ++option)
        {
            std::cout << " [" << option->key() << "] " << option->text() << "/r/n";
        }

        std::cout << std::endl << "/t > " << std::flush;
    }
}