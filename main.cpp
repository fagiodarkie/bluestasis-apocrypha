#include <iostream>
#include "Engine/Chapter/Chapter.h"
#include "Engine/Screen/ScreenLoader.h"

int main() {
    engine::chapter::Chapter startChapter;
    startChapter.load("..\\data\\screens_1.json");

    engine::screen::ScreenLoader screenLoader(startChapter);

    screenLoader.mainMenu();

    std::cout << "Press any key to end the game" << std::endl;
    std::string in;
    std::cin >> in;
    return 0;
}
