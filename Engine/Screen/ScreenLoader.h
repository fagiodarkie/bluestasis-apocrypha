//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_SCREENLOADER_H
#define BLUESTASIS_APOCRYPHA_SCREENLOADER_H

#include <map>

#include "Screen.h"
#include "../Chapter/Chapter.h"
#include "../../GameState/IGameState.h"

namespace engine::screen
{
    class ScreenLoader {
    public:

        ScreenLoader(const chapter::Chapter& chapter, std::shared_ptr<gamestate::IGameState> gameState);

        void mainMenu() const;
        void loadScreen(chapter::Chapter::screenIterator screen) const;

    protected:
        const chapter::Chapter& _chapter;
        std::shared_ptr<gamestate::IGameState> _gameState;

        static void title();
        static std::string playerChoice();

        void writeOption(const std::string& key, const std::string& text) const;

        void writeOption(char key, const std::string& text) const;

        bool selectedOptionIsReserved(const std::string& selectedKey) const;

        void saveGame(const std::string& screenId, const std::string& name) const;

        void processReservedOption(const std::string& option, const std::string& screenId) const;

        void exit() const;

        const std::map<std::string, std::string> reservedOptions = {
                {"S", "Save"},
                {"M", "To Main Menu"},
                {"X", "Exit"}
        };

        const std::map<std::string, std::string> mainMenuOptions = {
                {"N", "New Game"},
                {"L", "Load"},
                {"X", "Exit"}
        };

        static void printScreenText(chapter::Chapter::screenIterator screen) ;

        void loadGame() const;
    };

}


#endif //BLUESTASIS_APOCRYPHA_SCREENLOADER_H
