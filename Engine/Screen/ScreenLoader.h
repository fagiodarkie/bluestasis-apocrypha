//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_SCREENLOADER_H
#define BLUESTASIS_APOCRYPHA_SCREENLOADER_H

#include "Screen.h"
#include "../Chapter/Chapter.h"

namespace engine::screen
{
    class ScreenLoader {
    public:

        ScreenLoader(const chapter::Chapter& chapter);

        void mainMenu() const;
        void loadScreen(chapter::Chapter::screenIterator screen) const;

    protected:
        const chapter::Chapter& _chapter;

        static void title();
        static std::string playerChoice();

        void writeOption(const std::string& key, const std::string& text) const;
        bool selectedOptionIsReserved(const std::string& selectedKey) const;

        void printScreenText(chapter::Chapter::screenIterator screen) const;
    };

}


#endif //BLUESTASIS_APOCRYPHA_SCREENLOADER_H
