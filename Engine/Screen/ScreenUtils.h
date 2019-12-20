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
    }

}

#endif //BLUESTASIS_APOCRYPHA_SCREENUTILS_H
