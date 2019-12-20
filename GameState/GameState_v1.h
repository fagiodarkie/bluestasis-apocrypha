//
// Created by apteros on 20/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_GAMESTATE_V1_H
#define BLUESTASIS_APOCRYPHA_GAMESTATE_V1_H

#include "IGameState.h"
#include "../thirdparty/serialisable/serialisable.hpp"
#include "Save/SaveEntry.h"

namespace gamestate {
    class GameState_v1 : public IGameState, public Serialisable {
    public:
        void saveGame(const gamesave::save::SaveEntry& saveEntry);

        SaveEntry getSave(const std::string& saveId) const;
    };

}

#endif //BLUESTASIS_APOCRYPHA_GAMESTATE_V1_H
