//
// Created by apteros on 12/12/2019.
//
#include "IGameState.h"

namespace gamestate {
    IGameState::IGameState(int version) : _version(version) {}

    IGameState::~IGameState() {}
}
