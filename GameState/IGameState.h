//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_IGAMESTATE_H
#define BLUESTASIS_APOCRYPHA_IGAMESTATE_H

#include "Save/SaveEntry.h"

namespace gamestate {
    class IGameState {
    public:
        IGameState(int version);

        virtual void saveGame(const gamesave::save::SaveEntry& saveEntry) = 0;

        virtual gamesave::save::SaveEntry getSave(const std::string& saveId) const = 0;

        virtual ~IGameState();
    protected:
        int _version;
    };

}

#endif //BLUESTASIS_APOCRYPHA_IGAMESTATE_H
