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
        GameState_v1();

        virtual void saveGame(const gamesave::save::SaveEntry& saveEntry) override ;
        virtual std::vector<std::string> saves() const override;
        virtual gamesave::save::SaveEntry getSave(const std::string& saveId) const override;

        virtual std::string audioDirectory() const;
        virtual std::string currentAudioFile() const;
        virtual void setCurrentAudioFile(const std::string& audioFile);

    protected:
        void serialisation() override;

        std::vector<gamesave::save::SaveEntry> _saves;
        std::string currentAudio;

        static const std::string FILENAME;
    };

}

#endif //BLUESTASIS_APOCRYPHA_GAMESTATE_V1_H
