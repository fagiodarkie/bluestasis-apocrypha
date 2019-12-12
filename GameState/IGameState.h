//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_IGAMESTATE_H
#define BLUESTASIS_APOCRYPHA_IGAMESTATE_H

namespace gamestate {
    class IGameState {
    public:
        IGameState(int version);

        virtual ~IGameState();
    protected:
        int _version;
    };

}

#endif //BLUESTASIS_APOCRYPHA_IGAMESTATE_H
