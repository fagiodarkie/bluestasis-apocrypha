//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_SCREENLOADER_H
#define BLUESTASIS_APOCRYPHA_SCREENLOADER_H

#include "Screen.h"

namespace engine::screen
{
    class ScreenLoader {
    public:
        ScreenLoader();

        void loadScreen(const Screen& screen) const;
    };

}


#endif //BLUESTASIS_APOCRYPHA_SCREENLOADER_H
