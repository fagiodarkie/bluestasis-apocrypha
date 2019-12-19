//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_SCREENUTILS_H
#define BLUESTASIS_APOCRYPHA_SCREENUTILS_H

#include <iostream>

namespace engine::utils {
    void ClearScreen()
    {
        std::cout << "\r\n\r\n" << std::endl;

    #/*if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif*/
    }

}

#endif //BLUESTASIS_APOCRYPHA_SCREENUTILS_H
